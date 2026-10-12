// STATUS: equivalent (tools/equiv.py level 3: 105 inputs, branch coverage 18/24, incomplete)
// core::XboxSaveDrive::vfunc_7 @ 0x00279160
extern unsigned char DAT_0052a228;
extern unsigned char DAT_0052a229;
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
 bool vfunc_7();
};
}
bool core::XboxSaveDrive::vfunc_7() {
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
    if ((DAT_0052a229 & mask) != 0) {
     int newState = (DAT_0052a228 & mask) ? 3 : 4;
     state = newState;
     resultState = newState;
     return false;
    }
   } else {
    DAT_0052a229 &= (unsigned char)~mask;
   }
  }
 }
 return resultState == 0;
}
