#include "microscope.hpp"
#include "visualiser.hpp"

Visualiser* Visualiser::instance = nullptr;

Visualiser::Visualiser(const std::string& outputName) :
    m_nodesAmount(0),
    m_file(outputName) 
{
    m_file << "digraph structs {\n\trankdir=HR; outputOrder=nodesfirst;\n";
}

Visualiser::~Visualiser() {
    m_file << "}\n";
    m_file.close();
}

Visualiser& Visualiser::GetInstance(const std::string& outputName) {
    if (instance == nullptr) {
        instance = new Visualiser(outputName);
    }

    return *instance;
}

void Visualiser::RemoveInstance() {
    if (instance) {
        delete instance;
    }

    instance = nullptr;
}

std::string Visualiser::CreateCtorNode(const std::string& name, const std::string& color) {
    std::string nodeName = std::to_string(m_nodesAmount++);

    m_file << nodeName 
           << " [style = filled label = \"" << name << "\" shape = \"doublecircle\" fillcolor = \"" 
           << color << "\"]\n";

    return nodeName;
}

std::string Visualiser::CreateOperatorNode(const std::string& name, const std::string& color) {
    std::string nodeName = std::to_string(m_nodesAmount++);

    m_file << nodeName 
           << " [style = filled label = \"" << name << "\" shape = \"ellipse\" fillcolor = \"" 
           << color << "\"]\n";

    return nodeName;
}

void Visualiser::CreateEdge(const std::string& from, const std::string& to, const std::string& label, const std::string& style) {
    m_file << from << "->" << to << " [style =\"" << style << "\", label=\"" << label << "\"]\n";
}
