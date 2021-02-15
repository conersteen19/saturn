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
If f(n) is element of O(n^k-e) for some positive e, then T(n) is element of Θ(nk)

If f(n) is element of o(nk) then T(n) is element of Θ( f(n) log(n) ) = Θ(nk log(n))

If f(n) is element of o(nk+) for some positive , and 
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