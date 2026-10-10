// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 6/6)
// FUN_00269590 @ 0x00269590
struct RefObject { virtual void slot0(); virtual void FUN_virtual1(); };
extern RefObject* DAT_00528388[4];
extern void* DAT_0042b2a4[];
extern void* DAT_0042b29c[];
extern void* DAT_0042b14c[];
extern void* DAT_003f6098[];
extern void* DAT_0042af64[];
extern int DAT_004cdbb0;
extern "C" void __stdcall XInputClose(void*);
extern "C" void __stdcall FUN_00013420(void*,int,int,void*);
extern "C" void FUN_00268330();
extern "C" void FUN_002684e0();
struct ControllerXBox { void** vtable; char pad[4]; void* handle; char rest[0x4a0-12]; };
struct ControllerSystemXBox { void** vtable; void** vtable2; int value; char pad[0x20-12]; ControllerXBox controllers[4]; void FUN_00269590(); };
void ControllerSystemXBox::FUN_00269590() {
 vtable=DAT_0042b2a4;
 vtable2=DAT_0042b29c;
 for(unsigned i=0;i<4;i++) { DAT_00528388[i]->FUN_virtual1(); DAT_00528388[i]=0; }
 for(int i=3;i>=0;--i) {
  ControllerXBox& c=controllers[i];
  void* h=c.handle;
  c.vtable=DAT_0042b14c;
  if(h) XInputClose(h);
  FUN_00013420((char*)&c+0x428,0x10,2,(void*)&FUN_00268330);
  FUN_00013420((char*)&c+0x18,0x34,0x14,(void*)&FUN_002684e0);
  c.vtable=DAT_003f6098;
 }
 DAT_004cdbb0=value;
 vtable2=DAT_0042af64;
 vtable=DAT_003f6098;
}