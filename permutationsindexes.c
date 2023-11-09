/*================================================================================================================================
  These functions are for generating indexes which represent all ways of permuting n elements of an array.
  For example, for all ways to permute 4 elements from an array, use the indexes from print_all_indexes(4).
  1 <= numberOfptindexes, ptindexmax < 2^32
  
  0 1 2 3
  0 1 3 2
  0 2 1 3
  0 2 3 1
  0 3 1 2
  0 3 2 1
  1 0 2 3
  1 0 3 2...
  
  Let i be the highest index such that A[i] < A[i+1] for i=0 to n-2.
  If no such i, finish.  
  Find minimum A[j] greater than A[i] from A[i+1], ...,A[n], swap A[i] and A[j], then sort ascending A[i+1] to A[n].
*/
uint32_t* initptindexes(uint32_t numberOfptindexes) {
  if (numberOfptindexes == 0) return NULL;
  uint32_t* output = malloc(numberOfptindexes*sizeof(uint32_t));  
  if (output == NULL) {
    fprintf(stderr, "Malloc Failed in initptindexes(%u).\n", numberOfptindexes);
  }
  uint32_t i;
  for(i=0; i < numberOfptindexes; i++) {
    output[i] = i;
  }
  return output;
}

void ptindexes_sort(uint32_t numberOfptindexes, uint32_t* ptindexes) {
  uint32_t sorted, temp, i;
  sorted = 0;
  while (sorted == 0) {
    sorted = 1;
    for (i=0; i<numberOfptindexes-1; i++) {
      if (ptindexes[i] > ptindexes[i+1]) {
        temp = ptindexes[i];
        ptindexes[i] = ptindexes[i+1];
        ptindexes[i+1] = temp;
        sorted = 0;
      }
    }
  }
  return;
}

uint32_t* get_next_ptindexes(uint32_t numberOfptindexes, uint32_t* ptindexes) {
  uint32_t temp, i, j, minindex, minindexfound;
  if (numberOfptindexes == 1) {
    if (ptindexes != NULL) free(ptindexes);
    return NULL;
  }
  for (i=numberOfptindexes-2; ;i--) {
    if (ptindexes[i] < ptindexes[i+1]) {
      minindex = numberOfptindexes-1;
      minindexfound = 0;
      for (j=i+1; j<numberOfptindexes; j++) {
        if (ptindexes[j] > ptindexes[i]) {
          if (minindexfound == 0) {
            minindexfound = 1;
            minindex = j;
          } else {
            if (ptindexes[j] < ptindexes[minindex]) minindex = j;
          } 
        }
      }
      temp = ptindexes[i];
      ptindexes[i] = ptindexes[minindex];
      ptindexes[minindex] = temp;
      if (numberOfptindexes - i > 2) ptindexes_sort(numberOfptindexes - i - 1, ptindexes + i + 1);
      return ptindexes;
    }
    if (i == 0) {
      if (ptindexes != NULL) free(ptindexes);
      return NULL;
    }
  }
  return NULL;
}

void print_ptindexes(uint32_t numberOfptindexes, uint32_t*ptindexes) {
  uint32_t i;
  if (ptindexes == NULL) {
    printf("NULL\n");
    return;
  }
  for(i=0; i < numberOfptindexes; i++) {
    printf("%u ", ptindexes[i]);
  }
  printf("\n");
}

void print_all_ptindexes(uint32_t n) {
  uint32_t*ptindexes = initptindexes(n);
  uint64_t ptixcount = 0;
  while (ptindexes != NULL) {
    print_ptindexes(n, ptindexes);
    ptixcount++;
    ptindexes = get_next_ptindexes(n, ptindexes);
  }
  printf("There are %lu permutations for n=%u.\n", ptixcount, n);
}

/*================================================================================================================================*/

