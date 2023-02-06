#pragma once

#include <string>
#include <iostream>
#include <fstream>

template <class T>
class Microscope;

enum class TransferType {
    Move,
    Copy
};

class Visualiser {
    public:
        static Visualiser&  GetInstance(const std::string& outputName = "./dumps/graph.txt");
        static void RemoveInstance();

        template <class T>
        std::string CreateObjectNode(const Microscope<T>& object) {
            std::string nodeName = Microscope<T>::GetTypename() + std::to_string(m_nodesAmount++);

            m_file << nodeName 
            << " [shape = \"none\" label = <<table border = \"1\" bgcolor = \"" << object.GetColor() << "\">\n";

            m_file << "<tr><td>name</td><td>" << object.GetName() << "</td></tr>\n";
            m_file << "<tr><td>value</td><td>" << object.GetData() << "</td></tr>\n";
            m_file << "<tr><td>address</td><td>" << &object << "</td></tr>\n";

            m_file << "</table>>]\n";

            return nodeName;
        }

        template <class T>
        void ProcessContruction(const Microscope<T>& origin, const Microscope<T>& result, const TransferType& type) {
            std::string ctorName = "";
            std::string ctorColor = "";
            ProcessCtorType(type, ctorName, ctorColor);

            std::string ctorNode = CreateCtorNode(ctorName, ctorColor);
            CreateEdge(origin.GetDotName(), ctorNode);
            CreateEdge(ctorNode, result.GetDotName());
        }

        template <class T>
        void ProcessContruction(const T& origin, const Microscope<T>& result, const TransferType& type) {
            std::string ctorName = "";
            std::string ctorColor = "";
            ProcessCtorType(type, ctorName, ctorColor);

            std::string ctorNode = CreateCtorNode(ctorName, ctorColor);
            CreateEdge(CreateElemNode(origin), ctorNode);
            CreateEdge(ctorNode, result.GetDotName());
        }
        
        template <class T>
        void ProcessBinaryOperator(const Microscope<T>& left, const Microscope<T>& right, const Microscope<T>& result, const std::string& operatorName) {
            std::string operatorNode = CreateOperatorNode(operatorName);

            CreateEdge(left.GetDotName(), operatorNode, "l");
            CreateEdge(right.GetDotName(), operatorNode, "r");
            CreateEdge(operatorNode, result.GetDotName());
        }

        template <class T>
        void ProcessChangingOperator(Microscope<T>& left, const Microscope<T>& right, const std::string& operatorName) {
            std::string newNode = CreateObjectNode(left);
            std::string operatorNode = CreateOperatorNode(operatorName);

            CreateEdge(left.GetDotName(), operatorNode, "l");
            CreateEdge(right.GetDotName(), operatorNode, "r");
            CreateEdge(operatorNode, newNode);

            left.SetDotName(newNode);
        }

        template <class T>
        void ProcessEqOperator(Microscope<T>& left, const Microscope<T>& right, const TransferType& type) {
            std::string color = (type == TransferType::Copy) ? "red" : "green";

            std::string newNode = CreateObjectNode(left);
            std::string operatorNode = CreateCtorNode("=", color);

            CreateEdge(left.GetDotName(), operatorNode, "l");
            CreateEdge(right.GetDotName(), operatorNode, "r");
            CreateEdge(operatorNode, newNode);

            left.SetDotName(newNode);
        }
    
    private:
        Visualiser(const std::string& outputName = "./dumps/graph.txt");
        ~Visualiser();

        template <class T>
        std::string CreateElemNode(const T& elem, const std::string& color = "white") {
            std::string nodeName = std::to_string(m_nodesAmount++);

            m_file << nodeName 
                << " [style = filled label = \"" << elem << "\" shape = \"box\" fillcolor = \"" 
                << color << "\"]\n";

            return nodeName;
        }

        std::string CreateCtorNode(const std::string& name, const std::string& color = "white");
        std::string CreateOperatorNode(const std::string& name, const std::string& color = "white");

        void CreateEdge(const std::string& from, const std::string& to, const std::string& label = "", const std::string& style = "solid");

        void ProcessCtorType(const TransferType& type, std::string& ctorName, std::string& ctorColor) {
            if (type == TransferType::Move) {
                ctorName = "move ctor";
                ctorColor = "green";

                return;
            }
            
            ctorName = "copy ctor";
            ctorColor = "red";
        }

        uint64_t m_nodesAmount;

        static Visualiser* instance;
        std::ofstream m_file;
};

