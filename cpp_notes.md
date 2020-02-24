# C++ Notes (from CS 2150)
## Aliases
```
alias cs='cd "/mnt/c/Users/coner/Google Drive/College Work/Semester 4/CS 2150/pdr"; git pull; cd ..'
alias cl='clang++ -Wall -g -o a.out'
alias run='./a.out'
alias memcl='valgrind --leak-check=full ./a.out'
```

## 1/15/20
Why C++?
- More efficient, more control, fast
-	Data and program rep in memory
-	Memory allocation

Hello World:
```cpp
 #include <iostream>
using namespace std;
int main() {
	cout << “Hello World” << endl;
	return 0;
}
```
Differences from java:
-	Always return 0 for compiler
-	“#” calls the precompiler to bring in resources before execution
-	In < > if with compiler
-	In “” if our own file (.h extension)
-	“Using” keyword is similar to an import, namespace is sort of like a package
-	Can not import with using OR have to call each variable or resource with “std::”
-	Use “cin >>” and “cout >>” to take information in and out, respectively

Primitive Types
-	Int
-	Can be 16, 32, or 64 bits depending on where it is compiled
-	Float
-	7 decimals accuracy
-	Double
-	15 decimals accuracy
-	Char
-	Bool

Operators and expressions
-	A condition can be either an int or bool
-	Loops are all identical- for, while, do while, break, continue

We compile with clang++ (single-pass compiler)

Functions: Methods are NOT a member of the class
```cpp
Return_type name (input_type input_name){
	Return return_type
}
```
C++ isn’t bright and will forget functions after they are used.  This can be fixed by having function prototypes with the first line of the function but no contents, telling the compiler the code for that function is coming:
```cpp
Return_type name (input_type input_name);
```
## 1/17/20
Classes in C++
- We need to split up normal class programming into files
- Main method should go in its own class (.cpp is the extension), no specific name required; files must be included

Using an object is done like:
```cpp
IntCell m2(37);
```
Note the lack of an “equals”, not using pointers or references yet, just the object.  To call a default constructor you don’t use parenthesis.

Setting an object equal to another changes the contents of the object to the same as the other.  They stay distinct but the contents copy.

“.h” file: structure for a class.  Format as follows:
```cpp
#ifndef NAME_H
#define NAME_H
class Name {
	public:
		Name( type initialValue = initVal);
		returnType name (parameters) const;
    //const means the method will not modify the contents of the object (in this context) */
	private:
		type varName;
};
#endif
```
The actual body of the method is defined in the “.cpp” file format.  Make sure to include the .h file.  You also need double colon notation to prove you are referencing the methods for the object.  Example method:
```cpp
ObjectName::methodName(parameters) { //const, if necessary
	//Method contents
	Return return;
}
```
Note in constructors, you DO NOT need to list the default values as defined in the header.  The const transfers over and is on both.  Constructors look like:
```cpp
ObjectName::ObjectName(parameters) :
	fieldName( valueName ), fieldName2( valueName2), … {
}
```
Const can also be used to set a value at compiletime that cannot be changed, declared in constructor.  C++ compilation steps:
1.	Preprocessor- spits out preprocessed files
2.	Compiler- returns object files
3.	Linker- executable files
4.	Runs on Machine code
***Use “<<” to concatenate items to print, not “+”

Objects can be destroyed just as they are created.  In your header, define a destructor with a “~” before a copy of the constructor.

## 1/22/20
Preprocessing- going through a file and dealing with the “#” things
Examples
- #include <name> or “name”: direct copy of file specified to location specified
-	Includes can recursively call each other, breaking the preprocessor
-	Always place include statements in #ifs to prevent breaking
-	```#ifndef NAME```: if not defined; runs code within it if true; also works as #ifdef
-	```#endif```: end if any if
-	```#define NAME```: Defines a macro/direct text replacement; sort of a shortcut; like defining a constant; normally in all caps
-	Also works with objects, leaves them defined but not initiated

Pointers- stores a memory address of another object, either primitive or class, ALWAYS 8 bytes in size.  To declare, use a star:
```cpp
int * x;
Rational * rPointer;
```
This is used in expression DIFFERENTLY than in declaration:
```cpp
Int * x;
*x = 2;
```
This changes the value of the object being pointed to, not the physical pointer.

Ampersands (&) are used for reference types, used to get the address of something:
```cpp
X = &y
```
(\*) and (&) work inversely

You can use a double asterisk (\*\*) to have a pointer point to a pointer

Common pointer error: Not giving the pointer something to point to/not initializing the variable

## 1/24/20
Some items work using static memory- the computer knows how much memory will be used so it can allocate and deallocate for you.  If we don’t know the amount of memory needed, we need dynamically allocated memory to have more space on the fly.  To do this, we use the ```new``` keyword.  Ex. Declaring an array:
```cpp
Int * ages = new int[n];
```
Note that since it was defined with the “new” keyword, you need to delete it with the “delete” keyword.
```cpp
Delete pointer;
Delete [] ages;
```
One pitfall is to call a pointer to access a memory address whose object you have deleted.  Doesn’t cause an error so be aware.

Note that you can define primitive types just like you do objects to shorthand.  This is more efficient than making an integer in a pointer (1 line vs 4 lines):
```cpp
Int * x = new int(0);
```
Note that if a primitive type is created with the “new” keyword, you still must delete it.

You cannot delete memory that has already been deleted, causes “double free” error.

Accessing parts of the object: Each of the following are valid:
```cpp
Rational r;
r.num = 4;
//OR, with a pointer
Rational *r = new Rational();
(*r).num = 4;
//OR, as shorthand for above
r->num = 4;
```
Sometimes other classes need to access private data members from another class.  This is done with the ```friend``` keyword:
```cpp
class ListNode {
  private:
    friend class List;
 };
 ```
 Note that ```*``` is associative.  ```char* x, y``` makes x a char pointer but makes y a char.  To avoid this, move the star to the right: ```char *x, y```
 
 ## 1/27/20
 When requesting memory, double the space needed is allocated.  A key is put in front of the memory to note how large it is, making the ```delete``` function work.
 
 *References*: Similar to pointers with a few differences:
 1. Address cannot change
 1. Address must be set when declaring (result of above)
 1. Has implicit dereferencing
 
 Example of swapping reference values:
 ```cpp
 void swap(int & x, int & y) {
    int temp = x;
    x = y;
    y = temp;
}
```
Note the use of the ampersand.

After a reference is delcared, you can use them as a normal operator, without pointer notation with arrows:
```cpp
Square & squareRef = square;
int length = squareRef.sideLength;
```
*Call by Value*: Values are copied into a new variable to be manipulated by a function.  Can be safer but is inefficient.

*Call by Reference*: References are passed as parameters.  Should be used to change actual values for an object, not copies of it.

*Call by Constant Reference*: Same as Call by Reference except with the ```const``` keyword before parameters.  Means the parameters won't be modified.

Returning types can be done like calling (value, reference, etc.)

C++ provides 4 default methods when declaring anything:
- Default constructor
	- Does nothing
- Copy constructor
	- Copies all bytes of old one into new one
	- Doesn't care about contents
- Destructor
	- Called with ```delete``` function or when code goes out of scope.
- operator=()
	- Tells cpp how to use '=' operator between two objects
	- Declaration will be in different statement than the equals
	- Just copies bytes, no knowlege of contents

## 1/29/20

You can override how any operator works between two objects.  For example, you can change how '<<' works for cout.

C++s default library is rather weak compared to Javas.  Thus, we have limited options for objects in C++.

*Vectors*: Similar to array in C++.  Has a few problems: can't be copied with '=', no notion of capacity, no index validity checking.  Some methods:

- int size(): how big it is
- int capacity(): how much space there is, not how much is in the vector
- void reserve(int newCapacity): specify size of the vector
- void push_back(Object e), pop_back(): used for stack-like operations
- Object& back(), front(): return end and beginning of vector
- Object& at(int x): get object at index
- Object& operator[](int x): overrides bracket syntax, not smart like 'at' is

*Iterators*: Nested type that represents position in a vector.  Iterators use overrides for shorthand to save time:

- ++: moves forward; --: moves backward
- \*: removes pointer to object at iterator
- ==, !=: true if same location, false otherwise
- use begin() and end() to point to the beginning or end of vector.

Use of an iterator looks as follows:
```cpp
for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
	cout << *it << endl;
}
```

Vectors can do special functions with iterators: insert, erase are examples.

## 1/31/20

While Java uses inheritance to write code, C++ uses templates for functions and classes.

Function templates look as follows:
```cpp
template <typename Comparable>
const Comparable& findMax (input){
	//function
}
```
Note that no type is specified.  This tells C++ that this is a template.  We can then use this template for multiple types instead of creating unique methods for each.  It will check for operators in the function to properly override them.

You can also make these templates for classes to expand to different types of objects:
```cpp
template <typename Object>
class NewObject {
	public:
		NewObject(const Object& initValue = Object()) : storedValue(initValue) {}
		//Some Methods
	Private:
		//Some values
}
```
Note that templates can have more than one parameter, nontype parameters, and have default values for those parameters.

*Stacks*: Last In, First Out.  Like a stack of papers, add values on top, take next value from top.  Opposite is a queue.  Java provides default methods in their class such as push (insert at top), pop (delete from top), and top (get top value).  Example uses include postfix calculators, activiation records,  and symbol balancing.

Stacks can be implemented with a linked list, array, or vector.

## 2/5/20
*Radix to decimal*: Conversion of bases from another type to decimal.

*Decimal to radix*: Conversion from a base 10 number to a radix number.  Divide by radix number, take whole values left (NOT REMAINDER) and redivine, storing the remainders in order until no more redivisions are required (i.e. spits out 0r_something_).  Answer is remainders in REVERSE order.

C++ supports specifying base by leaders on a integer.  A leading '0' on a number specifies an octal (base 8) while a leading '0x' specifies a hexidecimal (base 16).  These two work well but others don't have much use.

Binary doesn't have an easy way to specify it is a binary number.  There is, however, an easy way to go between octal and hexidecimal.  Each 4 binary digits correspond to a single hex digit.  (ex. 1101<sub>2</sub> = d<sub>16</sub>)

The first computer build was the ENIAC.  Uses vacuum tubes and computed ballistic tables and an insane amout of power.  The vacuum tubes ran slow and binary representation became more popular with future technologies that allowed storing information in cells to be easier.  This allowed binary to enter the mainstream.

C defines the size of an integer or variable by implemetation definition.  It can be anywhere between small and massive.  Most machines run 32 bit integers but some run 64 bit integers depending on the machine and operating system.  ```sizeOf(int)``` tells you how large your int is.

*The Endian Debate*: Computers can change which bit is the most signifigant.  **Big-Endian** works how we think with the largest bit on the far left.  Computers, however, think in **Little-Endian** which puts the largest bit the furthest to the right.  This is primarily due to addressing; the highest address should have the highest value, which is the right most digit.  Note that this effects ONLY the BYTES, NOT the BITS.  Example: in big-endian, 0xdeadbeef; in little-endian, 0xefbeadde.  The primary issue comes with network communication.  All network communication is generally done in big-endian while computers run in little-endian.

*Integer Representation*: We generally reserve the left-most bit for the sign of the integer and use the rest to define numbers.  One must be careful; at first glance, two 0s exist.  100...0 is a -0 while 000...0 is a 0.  We deal with this a few ways:

- One's Compliment:
	- ![One's Comp](resources/onescomp.png)
	- No longer used
- Two's Compliment:
	- ![Two's Comp](resources/twoscomp.png)
	- Most commonly used
	- One more negative value as compared to positive values

When integers overflow, it will effect the sign bit at the beginning and change the sign/magnitude of the bit.  Note that, by how Two's Compliment works, this overflows from the max to the min value (which has a magnitude one greater than max!).

Note that C++ also has the ability to have unsigned ints.  Thus, we just remove the signed bit and have a lot more potential values.  This is commonly found for returning the size of an object as they cannot go negative.

## 2/7/20
*Real Numbers*: Used to use fixed point real numbers: they only used the decimal point in a single spot and stuck a decimal at the end, doesn't work for infinite fractions.  Now we use floating point fractions in scientific notation: sign bit, mantissa bits, and exponent bits.  They use the breakdowns as follows:

- bit 1: sign bit, 1 means negative (1 bit)
- bits 2-9: exponent (8 bits)
- bits 10-32: mantissa (23 bits)
	- mantissa= 1.0 + (sum){i=1},{23} b_i/2^i

And exponent values work as follows:

- 0: zeros
- 254: exponent-127
	- The value of 127 is called the exponent offset or the bias
- 255: infinities, overflow, underflow, NaN

*Converting float from binary to decimal*:

Given: 0100 0001 1100 1000 0000 0000 0000 0000

First bit -> sign = (+)

Next 8: 100 0001 1 -> exp = 131 - 127 = 4

Mantissa: 100 1000 0000 0000 0000 0000 -> mantissa = 1.5625

- The '1' bits in positions 1 and 4 represent (1/2)^1 and (1/2)^4; That's 0.5 + 0.0625 = 0.5625, add one to get the final value.

-> 1.5625 * 2^4 = 1.5625 * 16 = 25.0

*Converting float from decimal to binary*:

Take out sign bit.

Find what power of 2 is required to bring the number to 1.0 <= x < 2.0.  Multiply -> negative, divide -> positive.

Mantissa = f/2^exponent.  Make sure to subtract 1 to get your decimal range.

Max value of this form: 2 * 2^127 = 3.402823 * 10^38; Min (i.e. closest to 0) value for this form: 1 * 2^-126 = 1.175494 x 10^-38

Note that this form is not spatially uniform... changing one bit doesn't produce a 'constant' change.  Higher exponents will 'gain' more when the mantissa increases.

## 2/10/20

When you have a repeating decimal appear during its binary conversion, you can't accurately store it.  Thus you end with not exactly the same number, just long trains of decimals that aren't quite whole numbers.  This means comparisons with floating point numbers can lead to stealthy logical errors.  If you want to get around this, set a decimal criteria for how close things are and compare that (```bool test = fabs(x-y) < error;```).

You can test for these repeated decimals by looking in the decimal form.  If its denominator has factors that are not factors of the radix, it will repeat (and in our case, radix = 2).  To get around this you can use a rational class or more digits (BigFloat).

In 64 bits, the layout is as follows:
- 1: sign bit
- 2-12: exponent (11 total)
- 13-64: mantissa (52 total)
- Exponent offset: e^(e-1)-1 = 1023

*Arrays*: Primative type that holds objects in a list like format.  Can be specified either of these ways:
```cpp
int someInts[3];
int someInts[] = {1,2,3};
int* someInts = new int[3]; //requires deletion with the delete[] keyword
```
Note when making an array, it allocated one more space for a pointer to the array.  I.e. array\[3\] reserved 4 spots in memory.

Note that C++ doesn't allow you to delete the value of an array name.  This is due to the complier doing deallocation itself and it doesn't want to lose where that array is.  Imagine this as a constant pointer.

Notes to remember about arrays:
- No index checking/bounds checking (doesn't know if you're asking about an index out of range)
- When passed as an argument, it has no clue of the size.  Will have to pass as a parameter.
- Cannot be copied or compared with = or == (checks if same memory location), respectively.  Must be done manually.

## 2/12/20
The array "pointer" created points to the first value of the array.  The array then increments its address by the size of the object so the computer always knows where to look.  Multidimensional arrays are organized by the furthest right index incremented in memory first then moving all the way to the right.  This is known as *Row Major Order*.  I.e. a\[0\]\[0\] -> a\[0\]\[1\] -> ... -> a\[1\]\[0\].

Due to the way C++ works, you can have bounds overflow and be accessing a different cell than you may think.  As an example, in a 1x2 array, a\[1\]\[2\] == 1\[0\]\[5\].

*Passing parameters into main*:
```cpp
int main(int argc, char* argv[]){    //char* is known as a C-string
	return 0;
}
```
Note when you specify no command line parameters, argc = 1 b/c argv\[0\] is the name of the program.  

C-strings can be converted to a string with the ```string s()``` method.  Then they work as we intend.

*Order of Growth*:
- Big O: runs less than (<=) a certain bound; upper bound
- Big Ω: runs greater than (>=) a certain bound; lower bound
- Big Θ: runs following a certain function; tight bound
- ![Big Notation](resources/bignotation.png)
- Note that these only apply to large amount of values and is negligible at smaller numbers

To analyze a function f(n) as compared to a function g(n), we assusme f(n) is above Big Θ and Below Big O.  We also assume we are finding the worst case element.  This leads us to define:
- O(g) is the set of functions f, st. f(n) <= c\*g(n) for all n > n_0
- Ω(g) is the set of functions f, st. f(n) >= c\*g(n) for all n > n_0
- Θ(g) = O(g) and Ω(g)
	- Θ(g) is the asymptotic order (or just the order) of g
	- f is element of Θ(g) is read as "f is (asymptotic) order g"

Note that the c is used to cancel any constants seperating f(n) from g(n).  This removes the time unit from the equation (things like the computer/OS used) to allow a direct comparison.

## 2/14/20
Proof for Big-O examples:
```
Prove: 10n is an element of O(n)
10n is an element of O(n)
10n <= c and for all n > n_0
	let c = 10
10n <= 10n for all n >= n_0
1 <= 1 for all n >= n_0
QED
```
Note any n_0 or c can be chosen, but they should be picked strategically to prove understanding.

Note we use "is an element of" NOT =.  This is on purpose; Big-\* are sets.

Note Big-Ω uses the same proof, just with a comparator change from less than to greater than

To prove Big-Θ, we must prove the function is Big-O AND Big-Ω of the same function.

Little-O also exists.  This uses less than instead of less than or equal to.  This strictly defines something as a lower bound which implies it **cannot** be Big-Θ.  Little-Ω also exists.

Some functional properties:
- Reversing big-O: f ∈ O(g) ⇔ g ∈ Ω(f)
- Adding big-O: O(f + g) = O(max(f, g))
    - Similar equations hold for Ω and Θ
- Transitive: If f ∈ O(g) and g ∈ O(h), then f ∈ O(h)
	- Big-O is transitive, as are all the others (big-theta, big-omega, little-oh, and little-omega)
- Reflexive: f ∈ Θ(f)
	- As are big-O and big-omega
- Symmetric: If f ∈ Θ(g), then g ∈ Θ(f)
	- Big-Oh is not symmetric! (neither are Ω, o, or ω)
- Θ defines an equivalence relation on the functions

Reminder that c^n grows faster than n^k for all c, k > 1.

Loops generally run in n time.  As you nest them, it raises per each loop (3 nested loops -> n^3).  Remember to take the worse case route.

Examples of algorithm running times:
- Constant: Size of vector, linked list insert or delete, finding nth element in array/vector
- Log (space cut in half each iteration): Binary/balanced tree search
- Linear (process for each element): printing, find in unsorted array, find in link list, doubling a vector's array
- LogLinear (doing a log operation on each element): mergesort, heapsort, quicksort (on good day), inserting at log time
- Quadratic: insertion sort, bubble sort, selection sort, quicksort (on bad day), graph algos, double nested loops

## 2/17/20
*Trees*: Each element in a set that has up to n connected children.  Unlike lists, not every element has an individual direct relationship with its following element.  Trees can have multiple children, creating more complex web connections.

Lingo:
- Parent: Node above the current node
- Child (left and right): Nodes below the current node
- Root: Node with no parent
- Leaf: Node with no children
- Siblings: Two nodes with the same parent
- Height of a node: *Longest* path from current node to a leaf
- Depth of a node: Longest path from current node to a root
- Path: sequence of nodes
- Length: number of edges (connections between nodes) in a path
- Internal Path Length: Sum of the depths of all nodes in a path
- Ordering:
- ![-Fix Notation](resources/treeorder.png)
	- Note that infix notation can get confusing while working with expression analysis.  Parenthesis matter in order to properly enforce order of operations.

General types of trees:
- Parse tree: builds a tree out of an equation in order to properly interpret it.
- Geneology tree: has complex relationships between nodes (i.e. steps, greats, etc.)
- First Child/Next Sibling notation: Each TreeNode has a firstChild and a nextSibling field to create trees with n number of children per layer

*Binary Search Trees*: Max of 2 children per node.  Nodes to the 'left' of the current node are less than the current node; nodes to the 'right' of the current node must be greater than it.  No duplicates are allowed.  BST Methods:
- Find: look at current node (starting at root).  If less than value, recurse left.  If greater than value, recurse right.  If you reach a null,  it is not in tree.
	- Note that this is still a LINEAR algorithm assuming the tree doesn't have to be balanced.
- Insert: Do find, insert when you find a null.
	- Example Code:
	```cpp
	void BST::insert(int x, BinaryNode * & curNode) {
    		if (curNode==NULL)
      			curNode = new BinaryNode(x,NULL,NULL);
   		else if (x < curNode->element)
        		insert(x, curNode->left);
    		else if (x > curNode->element)
        		insert(x, curNode->right);
    		else
        		;    
	}
	```
- Find Max: Keep going right until NULL
- Find Min: Keep going left until NULL
- Removing (no children): remove the node outright
- Removing (one child): replace node with child
- Removing (two children): replace with next least child in the RIGHT subtree of the node to be removed (i.e. next highest number in the tree)
	- Note this also works with the next smallest value; however, in this course, we will use the next highest value

Note that the max height of a tree is 2^(h+1)-1.  (Proved by induction)

## 2/19/20
Perfect binary tree: full elements on every level => that it can only hold 2^n-1 elements (n > 0).

*Expression Tree*: A way to keep internal representation of a math equation.  Can be written in pre/in/post-fix.  You can build a tree (from postfix) as follows:
- Use a stack of node **pointers**.  This is so we can properly change the objects and their values.
- Push values to the stack
- When you reach an operator, pop the top two values of the stack as the operator's children and push the operator to the stack

*AVL Trees*: A type of balanced binary tree that keeps the tree balanced to allow Θ(logn).  We do this by manually balancing the tree when certain nodes are added to it that unbalance it.  We define balanced as *the height of the left and right subtrees differ by at most 1*.

To maintain this balance, we give AVL nodes an additional variable: a balance factor.  The balance factor is the height of the right subtree minus the height of the left subtree.  This value should be between -1>=bf>=1 and the tree should adjusted if it reaches either -2 or 2.

## 2/21/20
AVL Trees run find the same as a BST.  However, insert is slightly different.  If the inserted node causes an unbalace in the tree, the tree will have to be 'rotated'.  The balance factors that can be modified are those only in the path of the insert of the node.  Insert still runs in log(n) time.  These rotations work as follows:
- Start from inserted node.  Work way up until you hit a node that is unbalanced (-2 or 2).  This implies that the lowest nodes will fix the higher up nodes, meaning only one rotation will be necessary.
- One of the following cases will cause the rotation:
	- Left subtree of left child of x
	- Right subtree of left child of x
	- Left subtree of right child of x
	- Right subtree of right child of x
- The first and last case require a single rotation.  The middle two require a double rotation.

*Single Rotation*: Used for a left-left or a right-right imbalance.  The node below the unbalanced node becomes the new parent for the unbalanced node.  The unbalanced node the becomes a child of the lesser side of the tree and takes on that subtree as a child.  Works either right or left.
- Note that the subtrees will change with the node: if a right rotation, the node moving up's right tree *moves up* with the node and enters its new right subtree with the previous values.  Same as reversed with the left.
- Node that at least one node will move up and one will move down, simultaneously increasing and decreasing the depth.

*Double Rotation*: Used for a left-right or right-left imbalance.  Double rotations are used as two independent single rotations: one on a child and one in the other direction on a parent.  I.e. in a node inserted in a left child's right subtree, rotate around the left child to the left.  The rotate the node to the right.  The same works in reverse.

Note you can determine what type of rotation you need based on the signs of the balance factor of the unbalanced node and the child of its direction.

Other runtimes: remove is log(n), print is n.

## 2/24/20
*Tail Recursion*: Returning exact values instead of performing an operation on each call of the function.  Tail conversion is recognizeable by a compiler and can be optimized into a for loop automatically.  

*Red-Black Trees*: A type of tree where each node is either RED or BLACK.  They also rotate and move nodes around just like an AVL tree.  The properties of a R-B tree are as follows:
- All nodes are red or black
- Root is always black
- Leaf Nodes (null children) are always black
- Both children of every red node are black (no red nodes on top of each other)
- Every simple path from the node to any descendent leaf takes the same number of black nodes
	- This implies the max path length will be 8 nodes long (half black, half red)
	- This makes *layers* in the tree of black nodes specifying depth... ok to have red between them
Inserting in R-B trees has a few cases:
- Insert as normal for BST and color it red
- One of 5 cases occurs:
	- The new node is the root node
	- The new node's parent is black
	- Both the parent and uncle (aunt?) are red
	- Parent is red, uncle is black, new node is the right child of parent
	- Parent is red, uncle is black, new node is the left child of parent

Removing works similarly to an BST as well but has **6** removal cases as well.  These are:
- N is the new root
- S is red
- P, S, and S's children are black
- S and S's children are black, but P is red
- S is black, S's left child is red, S's right child is black, and N is the left child of its parent
- S is black, S's right child is red, and N is the left child of parent P

Both of these always run at log(n) time.  This means they are consistenly faster than AVL trees and this is their primary use.  These are some benefits with history and less rotations but those are sort of ignored.

*Hashing*: Used for CONSTANT TIME find().  Stores in key-value pairs, meaning it can be near constant if we 'encode' and 'decode' information into hashes.  This works by putting your key into an HASH function which converts your key into an unsigned integer.  You then store the value into that key's hash (its 'number') so we can always know where to find it based on your hashing algorithm.

These hash functions must meet certain conditions: must be deterministic (always returns the same thing), must be fast, and must be evenly distributed.

