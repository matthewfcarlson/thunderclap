// STATUS: (regression case, wrong) equivalent/0x0028aea0.cpp before native10: no case 0x12110e and 0x121111 in the wrong group; must fail
// pure3d::DefaultChannelHandler::vfunc_5 @ 0x0028aea0
#include "gen/pure3d.h"

namespace pure3d {  }
void pure3d::DefaultChannelHandler::vfunc_5(int __p0, int __p1, int __p2, int __p3) { unsigned int * header = (unsigned int *)__p0; unsigned int * size = (unsigned int *)__p1; unsigned int type = (unsigned int)__p2; unsigned short count = (unsigned short)__p3;

 unsigned a=0,b=0; *header=0;
 switch(type) {
 case 0x121100: case 0x121107: case 0x121109: case 0x121111: case 0x121113: a=count*4; b=count*2; *header=0x1c; break;
 case 0x121101: a=count*8; b=count*2; *header=0x1c; break;
 case 0x121102: a=count*4; b=count*2; *header=0x2c; break;
 case 0x121103: a=count*8; b=count*2; *header=0x2c; break;
 case 0x121104: a=count*12; b=count*2; *header=0x1c; break;
 case 0x121105: a=count*16; b=count*2; *header=0x1c; break;
 case 0x121106: a=count*8; b=count*2; *header=0x1c; break;
 case 0x121108: a=(((int)count-1)>>5)*4+4; b=count*2; *header=0x1c; break;
 case 0x121112: a=count*6; b=count*2; *header=0x1c; break;
 case 0x121114: a=count*3; b=count*2; *header=0x1c; break;
 }
 *header=(*header+7)&~7u;
 *size=((a+3)&~3u)+((b+3)&~3u);
}
