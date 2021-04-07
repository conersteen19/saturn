# CS 4102: Algorithms Notes

- Quizzes can be retaken up to 3 times but must be taken during quiz days
- HW is due at hard deadline but the soft deadline is suggested for feedback
- Final has no retries but you can retake the other quizzes during the final window.

## Divide and Conquer/Sorting
Sorting is reordering a list to meet a set of criteria.  We will focus oin key comparison for this definition of sorting.  We do this because it is general, operations are proportional, and is usually expensive compared to things such as hashing.  We assume non-descending order for simplicity.  Terminology:
- Comparison sort: compare keys and move items.
- Adjacent sort: only swap adjacent elements.
- Stable sort: two items with the same value appear in the same order as initially given.
- In-place sort: uses at most Θ(1) extra space, e.g. not allocating another array of size Θ(n).

### Insertion Sort
Strategy:
- Let first section of list be sorted.
- Move next item down into sorted part of list in correct place, shift items up to make space.
- Loop until each item has been touched

*** Sometimes known as decrease and conquer

Why insertion?  Easy to understand, in-place, efficient if already or nearly sorted, good for small inputs, mostly stable.  Best case runs ```B(n) = n-1``` but worse case runs ```W(n) = Θ(n^2)```.  Average runs ```A(n) = n^2/4``` which is calculated as doing j/2 comparisons nested.

Insertion sort is considered the best of it's breed, meaning this type can't be done better than Θ(n^2).  This can be proven by a lower bounds argument which essentially states that worst case requires n(n-1)/2 comparisons at worst case when the list is completely backwards.

### Mergesort
Good example of divide and conquer algorithm.  Strategy:
```
solveProblem(input)
  if input is small, then solve directly (brute force?)
  else if input is big
    divide problem into n problems
    recurse invoke solveProblem on smaller problems
    combine solutions
    return bigger solution
```

Mergesort divides the list into two sublists of equal size and works with a sublist of size 1, then grows.  Code looks something like:
```
def mergesort(lst, first, last):
  if first < last:
    mid = (first + last) // 2
    mergesort(lst, first, mid)
    mergesort(lst, mid+1, last)
    merge(lst, first, mid, last)
  return
  
def merge(lst, first, mid, last)
  Define empty list C
  Find first items in A and B
  Move that item to end of C and remove original item
  Repeat til A and B empty
```
Runtime: Θ(nlog(n)) = 2T(n/2) + n (which is a recurrence relation).  It is also stable.

### Recurrence relations

Recurrence relationships are used to characterize algorithms and help understand how fast algorithms will run.

The primary example is the **MASTER THEOREM**.  This is given below.
```
If  T(n) = a T(n/b) + f(n) 
then let k = lg a / lg b = logb(a) (critical exponent)

Then three common cases:
If f(n) is element of O(n^k-ε) for some positive ε, then T(n) is element of Θ(nk)

If f(n) is element of O(nk) then T(n) is element of Θ( f(n) log(n) ) = Θ(nk log(n))

If f(n) is element of O(nk+ε) for some positive ε, and 
      a f(n/b) ≤ c f(n) for some c < 1 and sufficiently large n, then T(n) is an element of Θ(f(n))

Note: none of these cases may apply
```

This can be applied like so:
1. find k using the log
1. Compare the back function.  How does f(n) compare to n^k?
1. Can f(n) be an element of O(n^k-e) (or other cases?)
1. If so, you have your runtime!
1. If not, you will likely need another method (substitution, etc.)

Examples:

T(n) = T(n/2) = n
- k = log_2(1) = 0
- How does f(n) = n compare to n^0 = 1?  It grows more quickly...
- Looks like case 3.  n is element of Omega(n^0+.1) -> does n grow faster?  Yes!
- Θ(f(n)) = Θ(n)

T(n) = T(n/2) + lg(n) (base 2)
- Let's try the iteration method
	- T(n) = T(n/4)+log(n/2)+log(n) = T(n/4) + log(n) - log(2) + log(n) = T(n/4) + 2log(n)-1
	- T(n) = T(n/8) + log(n/4) + 2log(n) - 1 = ...
	- (Repeat d times)
	- T(n) = T(n/2^d) + dlog(n) - d(d-1)/2
	- Plug in example: T(1) = 1 -> d = log(n) -> 1T(1) + log(n)log(n) - log(n)log(n-1)/2 -> Θ(log^2(n))
- What about the master theorem?
	- k = log(1) = 0
	- How does log(n) compare to n^0?
	- Could it be case 3?  log(n) is element of Omega(n^0+e)?  No!
	- Breaks master theorem!  log(n) grows more slowly than any polynomial.
	- Master theorem doesn't apply.

### Example: Maximum Subarray problem

Problem: given list A of + and - ints, return i and j indices s.t. i <= j, 0 <= i,j <= A.len, A\[i,..,j\] sum of elements in A continuously.

Brute force runs n^3 time.  But we can do better.

What if we kept a separate array with sum from A\[0\] to A\[i\] leads to n^2 speed.  That is better but still exponential.

Can we do better?  We can try divide and conquer using this mergesort recurrence: T(n) = 2T(n/2) + n.  Can we match the 2T(n/2)?  We can split down the middle by recusing a MaxSum(left) and MaxSum(right) to find the max on each side.  What would happen if a solution crossed a dividing line?  This algorithm breaks...

What about the n step?  We can use n to check for the best solution that crosses the dividing line. We can do this by finding the best solutions that touch the node on the dividing line and merging them.  You can then compare that to MaxSum(l) and (r) and the max is your answer in nlogn time!

### Example: QuickSort

Quicksort is a divide and conquer algorithm and uses a strategy called 'partition' or split, a strategy that comes in a variety of methods.  Strategy is as follows:
- Call on subsection from first to last
- Choose a pivot element.  Element doesn't particularly matter but we use the first one often.
- Call partition.  Partition puts the pivot element in its proper place, smaller items below and larger items above
- Recurse on smaller and smaller groups on each side of the pivot

Different algorithms in choosing the pivot take different amounts of time.  We prefer Lomuto's Algorithm which uses the pivot element as the last item in the list.  Works as so:
- Look through list with value x, setting two values: i and j.  i is set whenever it sees the first value larger than the pivot and j is set when values stop getting larger after i.
- Drop x in where i is and shift i + 1 to j up one spot
- n - 1 comparisons.

This runs best case T(n) = 2T(n/2) + n-1, which is good if the sections are split right down the middle.  However, when sections are divided unequally, the recurrence goes to T(n) = T(0) + T(n01) + n-1 which lands at Θ(n^2).  The average case, however, is nlogn which is good.  We can avoid those worse case scenarios by choosing a random element between first and last and swapping with the last element or using the "median of three" method (choose first, last, middle, swap largest with max, sort).

This shows that quicksort works best with large, unsorted lists while insertion sort may be more efficient with smaller or sorted lists.  So change your base case to reflect this!

### Example: Closest Pair of Points

Problem: given a list of 2d points, find the pair of points that are closest together.

Brute force is, as expected, O(n^2).  But we can divide and conquer it:
- Split along x coordinate median
- Recursively find closest pair left and right
- Find closest pair crossing the line.  Don't do this straight up... find the smallest distance of your left and right and only test points within a distance of the midline that could possibly be shorter.  Called a 'runway'.
	- This could still be O(n^2) if all points are in runway.  You can get around this with geometry.  Progress up from y order and only check the next 7 points above it to see if less than delta- everything else must be too far!

This algorithm is efficient besides the point you will need to calculate a base case and sort the values by x and y.  It runs as T(n) = 2T(n/2) + Θ(n) which tells us it is Θ(nlogn) by the master theorem.

### Quickselect

The issue with Quicksort is the worst case.  If we could use a median to regularly split our list in the middle we can enforce better run time.  Quickselect has the same problem and has to do with finding the smallest item in a list.

Problem: given a list of numbers and value i, select the value x which is larger than exactly i - 1 elements.

Divide and conquer like so:
- Divide: select element p, Partition(P)
- Conquer: if i = index of p, done!  if i < index of p, recurse left.  Else recurse right.  (Only one recursive call!)
- Combine: Nothing!

We need to decide how to choose our pivot element.  If we take the logic we took above we will be stuck with the same time (Θ(nlogn)).  Randomized selection works pretty well but we can do better.

### Example: Median of Medians

Used to find something close to the median in Θ(n) time.  Promises that it is 30% < x < 70% of all values.  Done by:

- Split list into sublists of chunks of 5
- Find median of each chunk with insertion sort (20 comparisons)
- Return median of medians

This leads to a asymptotic Θ(nlogn) approach but has large constants i.e. isn't great for small lists.  Random is generally better but at the worst case isn't.

Run time for (comparison-based) sorting algos will ALWAYS be worse than or equal to Θ(nlogn)!  Proof can be done by decision tree: take the depth of the tree and prove asymptotic relationship.

### Heaps, Heapsort
Heap: almost complete binary tree where at any given node j, value\[j\] has a higher priority than either of its children.  Heaps can be max or min and are weakly sorted i.e. not perfectly sorted.

Heapsort is Θ(nlog(n)) and in place which is pretty good.  Also has heap-max/min, max-heap-insert (Θ(logn)), max-heapify (return heap to sorted format) (Θ(logn)) and heap-extract-max (Θ(logn)) to return max item.  Height of node is max(node->leaf), height of heap is max(root->node).

How do we build heaps?  We can use insert-heap on each element which is convenient but not the best.  We can do better with build-max-heap using heapify.  Given an unsorted array, we can call heapify on repeat from floor(n/2) (the last node that has children) to 1 of a unsorted array and heapify will rotate values to optimize the heap.  This comes out as Θ(n) with an upper bound of O(nlogn).

How can we sort a heap?  Well we know the max element is stored at the root.  We can touch this up by calling max-heapify on the root but with a heapify that decrements.  This shrinks the heap every operation AND in place!  Psuedocode:

```
Heapsort(A)
	for i = A.len to 2:
		flip A[1] and A[i]
		A.heapsize -= 1
		max-heapify(A,1)
```

### Example: Matrix multiplication with Strassen's Algo

Matrix multiplication is slow (up to O(n^3)).  We can speed it up with Stressen's Algo.  Stressen's algorithm contains a series of multiplications (called Qs) and those Qs can be used to calculate matrices which simplifies the recurrence to Θ(n^2.807) which is better at large cases.  People have slowly reduced it to n^2.39 over time.

## Trees

Trees are a common data structure with common problems.  Trees are defined as having children and only one parent in a linear like structure with a root note.  A spanning tree of graph G is a subgraph that contains every vertex and is also still a tree.  Involves removing a subset of edges to find optimal connections.  It is more common to find the minimum cost of a spanning tree.

### Kruskal's Algo

Kruskal's Algo involved building one tree and making the tree one bigger by adding the next best node (smallest weight).  Each edge added will connect to two trees and should be checked for cycles.  This works by building a forest-i.e. taking edges that are most efficient without care if they are connected to the existing tree.  It then checks for loops and picks the next shortest node.  Uses a priority queue to check edges Θ(Elog(V)) for edges and find and unioin run in Θ(E(2f(V) + u(V))) which makes the overall algo O(V^3) (assuming find and union linear time).

In the past we have used Disjointed Sets to do the creation of sets and merging for us.  Time to figure out how.

We want to support makeSet(int n) to make n independent sets, findSet(int i) that checks what set i belongs to, and union(int i, int j) merges the sets containing i and j.  Can be implemented with other data structures but this ex uses arrays.

- makeSet(int n): make array of size n with labels for that set stored in each index.  The label must be an element of the set that label is referencing, but labels can represent more than one value.  Linear.
- findSet(int i): Look at index i.  If there return it, otherwise set i=a\[i\] and repeat.  Linear if you have to trace a long way but can be constant if lucky.
- union(int i, int j): findSet(i) and findSet(j) then change one of those labels to match the other.  Constant to change labels but 2\*linear to find them.

This can be optimized by storing the value of the joined arrays to whichever tree is smaller to keep size small.  You can also path compress by changing values whenever a new node is found higher up to jump some subnodes.

Union by rank yields Θ(m a(n)) which grows very slow.

### DFS

Depth-first search works by going as deep in a tree as you can until you reach a dead end then backing up and making another choice.  

DFS traverses a subset of E (the set of edges) and each node has a distance from the start.  All nodes can be 3 states.  Undiscovered nodes haven't been touched yet, finished are nodes you've backed up, and discovered nodes have been visited but will be revisited.

A common strategy is to use a stack.  Start at node s by pushing it to the stack and mark as visited.  While S is not empty, pop node and process by marking neighbors as visited and then pushing neighbor onto stack.  Repeating yields your DFS tree.  Note this is the same strategy as BFS but uses a stack instead of a queue.  We can also do this recursively which looks cleaner but functions the same.  You can also visit all vertices by calling the recursive function on every node in the graph.

DFS is great for finding cycles in the graph when directed.  We call edges that go from the current node to the root/ancestor a **back edge** and going from a root to a grandchild or leaf is called a **descendent edge**.  Finally, edges between leafs or other non-root nodes are called **cross edge**.  Going back to a gray node shows that you have a back edge.  This breaks in undirected graphs.

DFS runs in Θ(V+E) which is pretty good.  Space complexity is Θ(V)

Examples go as follows: Max degree of separation?  BFS!  Find most adjacent nodes?  Adjacency list.  Find bipartite (Nodes in set V1 or V2, edges only connect V1 to V2 or vice versa, no interior edges) graph?  Trees are bipartite so run DFS to check if cycles exist.  If not, good to go!  Longest path to node in DAG?  Find the longest path to each node as you go and record your length.

### Example: Topological Sort
Given a directed acyclic graph, construct a linear ordering of vertices s.t. if an edge exists from u to v, u must become before v in the list.

We can use DFS with start/finish times. Topologically sorted vertices appear in reverse order of their finish times.  We need to modify existing code in DFS-Visit to append the node to the finish list after its finished its processing.  Directions of arrows can be flipped to change order.

### Example: Strongly Connected Components in a Digraph
In a digraph, SCCs are subgraphs where all vertices are reachable from one another.  We often need to decompose a digraph into these SCCs.  You can view this as after exiting one SCC, you can't go back into the same one.  

There are several algos for this but we will use Kosaraju and Sharir's choice.  This involves finding the DFS and recording finishing times.  Then find the transpose of the graph.  The call DFS-Sweep on the transpose but do recursive calls on the nodes in order of decreasing u.f. (start with largest finish time?)  Forest made from this is the set of SCCs.

This works because of reversing edge direction, a node may be able to leave its tree but during the transpose may not be able to reach all notes.  If a node can reach a set of nodes going fowards AND backwards then we know it forms a SCC.  As long as we **don't go to visited nodes and start at the max finish time** we will end up with out SCCs.

### Dijkstra's / Prim's Algo

These are greedy graph algorithms that use nearly the same code.  Greedy means they make the best decision possible at each point.

Dijkstra's: Stars at unknown vertex.  Choose next vertex with shortest distance to next v, mark v as known, and then for each edge from v adj to unknown vertices, update w's dist if it is less than what is already stored.  Runtime depends on finding next shortest node, which in list form we can do in Θ(V^2) time. You can do this faster with a priority queue to knock down runtime to Θ(Vlog(V) + EV) due to decreasing a key which is slow and linear operation.

Prim's is the same structure, runtime, etc.  You start at a known node then record your node's distances to each adjacent node.  Then go to your shortest path and check that node for shorter paths.

We need to fix finding a node in a MST, reducing the value, and percolating the value.  If we gave each node an ID populated in another array with values of the heap stored in it.  For instance, a node with ID of 0 would store the distance to that node in position 0 of the second array.  You can then check that second array to find nodes in constant time.  This array can be called in indirect heap.  Make sure to update both arrays when percolating or moving values.  You then land at Θ(Vlog(V) + Elog(V))!

Runtime can be proved with an inductive argument.  The base case is the first node and it takes 0 distance to get from root to the root.  The inductive step assumed we have an optimal graph, what happens when we add one more?  We know that node is the next shortest as it comes off the queue.  We also know that the edge between that and any given node is the dist to that node plus the edge weight.  We can use exchange argument: compare our way with another way to prove our way is the best.  In other words a 'swap' doesn't make the solution better.  In our case, we can take a different path to our node.  But since we are pulling from a priority queue, we **know** that this path is either as good or worse than what we have.  QED.

## Greedy Algos and Dynamic Programming

These two methods are used to help optimize a variety of algorithms but have two different fundamental approaches.  Greedy algorithms involve making choices optimally and assuming they are correct while dynamic programming involves solving and storing solutions of subproblems.

### Example: Log Cutting 

Given a log of length n and the price of different lengths of log, what is the optimal way to cut the log to maximize profit?  Worse case is O(2^n) which we can do much better.

Imagine that we need to have a 'last cut' of the log.  Thus we assume that last piece is sold and we can find the optimal solution of the remaining log.  The values of each of these halves is independent from each other.  We can then say that the optimal place of that cut should be the max sum of cutting the shortest possible, the maximum possible (in this case, not cutting at all) or one of the values in-between.  So you can then loop through starting at a min value to find the optimal solution for that length and use that value to find increasingly higher maximums.  I.e. given cut(1) through cut(4), you can find cut(5) by comparing cut(1)+cut(4), cut(2)+cut(3), and cut(5)+cut(0).

This is a dynamic programming solution.  You a nested look making this O(n^2).  This uses **memoization** which is storing solutions to subproblems in a table instead of recomputing them.

### When does greedy work?

Greedy algorithms only work when the problem has optimal substructure and has the greedy choice property.  Optimal structure in the problem means that it can be arranged in a way that removing one option still keeps the same optimal solution.  Greedy choice property states that the first thing that was added to the solution must be correct- i.e. the largest coin is the best choice if possible.  You can prove this with individual proof by contradictions for each of the given values.   The coin contradiction proof could break easily with testing 12 coins with 1, 6, 10 sizes. 

