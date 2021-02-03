# CS 4102: Algorithms Notes

- Quizzes can be retaken up to 3 times but must be taken during quiz days
- HW is due at hard deadline but the soft deadline is suggested for feedback
- Final has no retrys but you can retake the other quizzes during the final window.

## Divide and Conquer/Sorting
Sorting is reordering a list to meet a set of criteria.  We will focus oin key comparison for this definition of sorting.  We do this because it is general, operations are proportional, and is usually expensive compared to things such as hashing.  We assume non-descenting order for simplicity.  Terminology:
- Comparison sort: comepare keys and move items.
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
