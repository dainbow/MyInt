# Introduction
As you now, c++11 gave us new features which can significantly increase performance of your programs - rvalue references and move semantics. 
However, a lot of programmers are still using only lvalue references in their programs.
So, I'll tell you more about these things.

# About rvalue references
Lvalue references has one problem: you can't write
  ```int& a = 5;```
because lvalue reference can be assigned only to lvalue. But if we want to make a reference to a temporary object? Rvalue references'll help us!

# About constructors 
Since rvalue references were added, there are 4 ways to construct some class T:

  ```T(T&)``` - nonconst copy consructor
  
  ```T(const T&)``` - const copy constructor
  
  ```T(T&&)``` - move constructor
  
  ```T(const T&&)``` - const move constructor
  
## Nonconst copy constructor
+ You can use this constructor only with lvalue objects, because rvalue ones can't be casted to this type.
+ It's not safe to use this constructor, because transmitted object can be changed
+ This constructor is pretty slow, because in case of deep copy it will have to copy big amount of data (For example, matrices 10x10)
 
So, usually nobody uses this constructor.

## Const copy constructor
+ You can use this constructor not only with lvalue object, rvalue objects can be interpreted as const lvalue object!
+ It's save to use this constructor, because transmitted object can't be changed
+ But in case of deep copy this constructor as slow as nonconst copy constructor

People who don't know about move constructors usually use only this constructor and their programs become really slow!

## Move constructor
+ You can use this constructor with rvalues and if you use std::move() you can transmit lvalue object to it. (Before doing this please read next point)
+ As you know that this rvalue is temporary object, you can do with its data everything you want. And if you transmit lvalue using std::move() you should know that its data may be corrupted after this function
+ In case of deep copy you can just swap pointers, so using of this constructor is extremely fast!

If you use this constructor, you can optimize some parts of your codes: actions with temporary objects and actions with objects which will be deleted soon.

# About assigment operator
There are also 4 types of assignment operators which have the same properties as corresponding constructors

# Let's test
I've wrote a simple [example](https://github.com/dainbow/MyInt/blob/master/src/main.cpp) to compare const copy constructor and move contructor (I won't test nonconst copy constuctor and const move constructor as they are useless)

Moreover, we will check impact of <elide-constructors> compilator optimization.

## Const copy constructor
![Copy]()
