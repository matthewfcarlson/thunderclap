// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 19/20, incomplete)
// FUN_003335e0 @ 0x003335e0
typedef unsigned int U;
extern U* __cdecl FUN_0031c680(U*, U, U, U);
struct Obj { char p0[0x18]; U mode,activeMode; char p20[0x10]; float scale,result; U alpha; char p3c[0xc]; unsigned char enabled; char p49[7]; U c50,c54,c58,c5c; char p60[4]; U c64,c68,c6c,c70; void FUN_003335e0(); };
void Obj::FUN_003335e0(){ struct Locals { U inverse,t1,t2,t3,t4; } local; local.inverse=255-alpha; activeMode=mode==0 && alpha>0?1:mode; float v=(float)local.inverse*0.0039215688593685627f*scale; if(!(v>=0.0f && v<=1.0f))v=v>1.0f?1.0f:0.0f; result=v; c58=c6c;c50=c64;c54=c68;c5c=c70; if(!enabled)return; switch(activeMode){case 1:c50=(c50&0xffffff)|((((c50>>24)*local.inverse)<<16)&0xff000000);break;case 2:case 4:c58=*FUN_0031c680(&local.t1,c6c,0xff000000,alpha);c50=*FUN_0031c680(&local.t2,c64,0xff000000,alpha);c54=*FUN_0031c680(&local.t3,c68,0xff000000,alpha);c5c=*FUN_0031c680(&local.t4,c70,0xff000000,alpha);break;case 3:case 5:c5c=*FUN_0031c680(&local.t4,c70,0xffffffff,alpha);break;} }
