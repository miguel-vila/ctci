#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isPerm(char* s1, char* s2) {
  int l1 = strlen(s1);
//  printf("l1 = %i\n", l1);
  int l2 = strlen(s2);
//  printf("l2 = %i\n", l2);
  if(l1 != l2) {
    return false;
  } else {
    int count1[255];
    int count2[255];
    for (int i = 0; i < 255; ++i)
    {
      count1[i] = 0;
      count2[i] = 0;
    }

    for (int i = 0; i < l1; ++i)
    {
      count1[ s1[i] ]++;
    }

    for (int i = 0; i < l2; ++i)
    {
      count2[ s2[i] ]++;
    }

    for (int i = 0; i < l1; ++i)
    {
      char c = s1[i];
//      printf("c= %c\n", c);
//      printf("count1[c] = %i\n", count1[c]);
//      printf("count2[c] = %i\n", count2[c]);
      if(count1[c] != count2[c]) {
        return false;
      }
    }
    return true;
  }
}

void checkPerm(char* s1, char* s2, bool perm) {
  if(isPerm(s1,s2) == perm) {
    printf("OK\n");
  } else {
    printf("FAIL\n");
  }
}

int main()
{
  checkPerm("hola","hloa", true);
  checkPerm("holaz","hloax", false);
  checkPerm("hola","hloar", false);
  checkPerm("holar","hrloa", true);
  checkPerm("hholar","hrloah", true);
  checkPerm("hholar","hrloahh", false);
  checkPerm("hhoolar","horloah", true);
  return EXIT_SUCCESS;
}