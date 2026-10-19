// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 24/24)
// core::XboxSaveDrive::vfunc_7 @ 0x00279160
#include "decls/data/platform/xbox/core.h"

namespace core {
struct XboxSaveDrive {
 char reserved0[0x60];
 int state;
 char reserved64[0x50];
 int resultState;
 char reservedB8[0x10];
 int active;
 unsigned char marker;
 char reservedCD[6];
 signed char port;
 signed char unit;
 char reservedD5[9];
 unsigned char mode;
 void FUN_00278b50();
 int vfunc_7();
};
}
int core::XboxSaveDrive::vfunc_7() {
 FUN_00278b50();
 if (mode != 0x55) {
  int portIndex = -1;
  int unitIndex = -1;
  if (marker != 0x55) {
   portIndex = port - 0x31;
   unitIndex = unit - 0x41;
  }
  if (portIndex >= 0 && unitIndex >= 0) {
   unsigned char mask = (unsigned char)(1u << ((portIndex + 4 * unitIndex) & 31));
   if (active != 0) {
    if (((*(unsigned char*)&DAT_0052a229) & mask) != 0) {
     int newState = ((*(unsigned char*)&DAT_0052a228) & mask) ? 3 : 4;
     state = newState;
     resultState = newState;
     return false;
    }
   } else {
    (*(unsigned char*)&DAT_0052a229) &= (unsigned char)~mask;
   }
  }
 }
 return resultState == 0;
}
