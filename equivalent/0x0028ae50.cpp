// STATUS: equivalent (tools/equiv.py level 3: 3010 inputs, branch coverage 4/4)
// pure3d::DefaultChannelHandler::vfunc_3 @ 0x0028ae50
#include "gen/pure3d.h"

namespace pure3d {   }
int pure3d::DefaultChannelHandler::vfunc_3(int __p0) { unsigned int channel = (unsigned int)__p0;
 unsigned int index = channel - 0x121100; if (index <= 0x14) { switch (index) { case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 14: case 17: case 18: case 19: case 20: return (int)(1); default: return (int)(0); } } return (int)(index & 0xffffff00u); }
