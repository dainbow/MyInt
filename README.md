# Introduction
As you now, c++11 gave us new features which can significantly increase performance of your programs - rvalue references and move semantics. 
However, a lot of programmers are still using only lvalue references in their programs.
So, I'll tell you more about these things.

# About rvalue references
Lvalue references has one problem: you can't write
  int& a = 5;
because lvalue reference can be assigned only to lvalue. But if we want to make a reference to a temporary object? Rvalue references'll help up!

# About constructors 
Since rvalue references were added, there are 4 ways to construct some class T:
  T(T&)
  T(const T&)
  T(T&&)
  T(const T&&)

