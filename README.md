# Permutation-indexing-in-c
Functions to iterate over all permutations of array elements.

With these functions, one can iterate over all permutations of array elements without creating copies of the either the array or the array indexes. It just creates an array of indexes, then a call to get_next_ptindexes() updates this array with the index values of the next permutation. See print_all_ptindexes() for an example of how to iterate over all permutations of n elements.

e.g. ./permutations.bin 3

0 1 2 

0 2 1 

1 0 2 

1 2 0 

2 0 1 

2 1 0 

There are 6 permutations for n=3.
