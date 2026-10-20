// STATUS: equivalent (tools/equiv.py level 3: 3024 inputs, branch coverage 12/12)
// pure3d::DefaultChannelHandler::vfunc_4 @ 0x0028ec30
struct Channel { unsigned FUN_00266c30(); };
namespace pure3d { struct DefaultChannelHandler {
virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual int vfunc_4(Channel*,void*,void*); virtual void vfunc_5();
int FUN_0028c580(Channel*,void*,void*); int FUN_0028c6b0(Channel*,void*,void*); int FUN_0028c7e0(Channel*,void*,void*); int FUN_0028c910(Channel*,void*,void*); int FUN_0028e160(Channel*,void*,void*); int FUN_0028cd80(Channel*,void*,void*); int FUN_0028ea80(Channel*,void*,void*); int FUN_0028ceb0(Channel*,void*,void*); int FUN_0028cfd0(Channel*,void*,void*);
}; }
int pure3d::DefaultChannelHandler::vfunc_4(Channel* c,void* a,void* b) {
unsigned index = c->FUN_00266c30() - 0x121100;
if(index > 20) return 0;
switch(index) {
case 14: return FUN_0028c580(c,a,b);
case 0: return FUN_0028c6b0(c,a,b);
case 1: return FUN_0028c7e0(c,a,b);
case 2: case 3: case 4: return FUN_0028c910(c,a,b);
case 5: case 17: case 18: case 19: case 20: return FUN_0028e160(c,a,b);
case 6: return FUN_0028cd80(c,a,b);
case 7: return FUN_0028ea80(c,a,b);
case 8: return FUN_0028ceb0(c,a,b);
case 9: return FUN_0028cfd0(c,a,b);
default: return 0;
}
}