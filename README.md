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
I've wrote a simple [example](https://github.com/dainbow/MyInt/blob/master/src/main.cpp) to compare const copy constructor and move contructor (I won't test nonconst copy constuctor and const move constructor as they are useless). By <compare const copy constructor and move contructor> I mean program with only const copy constructor written and program with both const copy and move constructor written.

Moreover, we will check impact of <elide-constructors> compilator optimization.
  
P.S. Imagine that we perform 100x100 matrices multiplication and every copy constructor takes O(n^2) time when move constructor takes O(1) time.

## Const copy constructor
![Copy](https://github.com/dainbow/MyInt/blob/master/dumps/Copy.png)
  
## Const copy + move constructors
![Move](https://github.com/dainbow/MyInt/blob/master/dumps/Move.png)
  
## Const copy + move constructors + optimization
![MoveOpt](https://github.com/dainbow/MyInt/blob/master/dumps/MoveOptimized.png)
  
## Results
<table>
    <tr>
        <th> Test name \ Amount </th>
        <th> Copy constructors </th>
        <th> Move constructors </th>
        <th> Temporary objects </th>
    </tr>
    <tr>
        <td> Const copy ctor </td>
        <td> 6 </td>
        <td> 0 </td>
        <td> 4 </td>
    </tr>
    <tr>
        <td> Const copy + move ctors </td>
        <td> 0 </td>
        <td> 6 </td>
        <td> 4 </td>
    </tr>
    <tr>
        <td> Const copy + move ctors + opt </td>
        <td> 0 </td>
        <td> 4 </td>
        <td> 2 </td>
    </tr>
</table>

As we can see, proper using of move semantics will help you to increase performance of your program: decreasing of copy operation is significant! Amount of unnecessary operations tends to zero!
  
# Conclusion
Thanks for reading! I hope that now you will use move semantics and rvalue references in all of your programs 🥇.
  
If you want to learn more about rvalue references, move semantics and perfect forwarding, I suggest you to read these articles:
+ [A Proposal to Add Move Semantics to the C++](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2004/n1690.html](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2002/n1377.htm)
+ [Impact of the rvalue reference on the Standard Library](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2005/n1771.html)
  
