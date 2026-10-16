// STATUS: equivalent (tools/equiv.py level 3: 2990 inputs, branch coverage 8/8)
// FUN_002b93f0 @ 0x002b93f0
#include "decls/data/engine/pure3d.h"

struct RandomState_2b93f0 {
 unsigned int first;
 unsigned int second;
 void FUN_0022aba0(int);
};
struct Object {
 char padding[0xc4];
 unsigned int limit;
 void target(float* result, unsigned int* value, unsigned int input, unsigned char randomize);
};
void Object::target(float* result, unsigned int* value, unsigned int input, unsigned char randomize) {
 if (randomize == 1) {
  if (!(DAT_00554bc0 & 1)) {
   DAT_00554bc0 |= 1;
   (*(RandomState_2b93f0*)&DAT_00554bb8).FUN_0022aba0(0);
  }
  unsigned int bound = limit;
  unsigned int first = ((*(RandomState_2b93f0*)&DAT_00554bb8).first & 0xffff) * 0x9069u + ((*(RandomState_2b93f0*)&DAT_00554bb8).first >> 16);
  unsigned int second = ((*(RandomState_2b93f0*)&DAT_00554bb8).second & 0xffff) * 0x4650u + ((*(RandomState_2b93f0*)&DAT_00554bb8).second >> 16);
  (*(RandomState_2b93f0*)&DAT_00554bb8).second = second;
  (*(RandomState_2b93f0*)&DAT_00554bb8).first = first;
  *value = (unsigned short)(((first << 16) + (second & 0xffff)) % (bound + 1));
 } else {
  *value = input;
 }
 *result = (float)((1.0 / (double)limit) * (double)*value);
}
