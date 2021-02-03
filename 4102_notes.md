# CS 4102: Algorithms Notes

- Quizzes can be retaken up to 3 times but must be taken during quiz days
- HW is due at hard deadline but the soft deadline is suggested for feedback
- Final has no retrys but you can retake the other quizzes during the final window.

## Divide and Conquer/Sorting
Sorting is reordering a list to meet a set of criteria.  We will focus oin key comparison for this definition of sorting.  We do this because it is general, operations are proportional, and is usually expensive compared to things such as hashing.  We assume non-descenting order for simplicity.  Terminology:
- Comparison sort: comepare keys and move items.
- Adjacent sort: only swap adjacent elements.
- Stable sort: two items with the same value appear in the same order as initially given.
- In-place sort: uses at most Theta(1) extra space, e.g. not allocating another array of size Theta(n)

