// STATUS: equivalent (tools/equiv.py level 3: 3026 inputs, branch coverage 12/12)
// pure3d::DefaultChannelHandler::vfunc_5 @ 0x0028aea0
namespace pure3d { struct DefaultChannelHandler { void vfunc_5(unsigned* header, unsigned* size, unsigned type, unsigned short count); }; }
void pure3d::DefaultChannelHandler::vfunc_5(unsigned* header, unsigned* size, unsigned type, unsigned short count) {
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