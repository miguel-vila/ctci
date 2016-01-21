#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isPerm(char* s1, char* s2) {
  int l1 = strlen(s1);
  int l2 = strlen(s2);
  if(l1 != l2) {
    return false;
  } else {
    unsigned int count[255];
    for (int i = 0; i < 255; ++i)
    {
      count[i] = 0;
    }

    for (int i = 0; i < l1; ++i)
    {
      count[ s1[i] ]++;
    }

    for (int i = 0; i < l2; ++i)
    {
      count[ s2[i] ]--;
    }

    for (int i = 0; i < l1; ++i)
    {
      char c = s1[i];
      if(count[c] != 0) {
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