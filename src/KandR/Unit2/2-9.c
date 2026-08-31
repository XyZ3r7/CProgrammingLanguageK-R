//
// Created by XyZ3r7 on 5/15/26.
//
#include <stdio.h>

int bitCount(unsigned x) {
   int b;

   for (b = 0; x != 0; x >>= 1) {
      if (x & 01) {
         b++;
      }
   }
   return b;
}

int bitCountFaster(unsigned x) {
   int b;

   for (b = 0; x != 0; x &= (x - 1)) {
      b++;
   }

   return b;
}
