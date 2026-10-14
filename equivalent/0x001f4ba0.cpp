// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001f4ba0 @ 0x001f4ba0
struct State {
 unsigned int first, second, value, handle, limit, extra;
 unsigned char flag;
 char pad[7];
 void FUN_0027af00();
 void FUN_0027af60(int, int);
};
extern unsigned int __cdecl FUN_002673a0(int,int);
struct Object;
extern Object* DAT_004e3760;
struct Object {
 char pad0[0x88];
 unsigned int f88, f8c;
 char pad90[8];
 unsigned int f98, f9c;
 State state;
 unsigned int fc0, fc4, fc8, fcc, fd0;
 char padd4[0x324-0xd4];
 unsigned int f324, f328, f32c, f330;
 float f334;
 unsigned int argument;
 Object* FUN_001f4ba0(unsigned int arg);
};
Object* Object::FUN_001f4ba0(unsigned int arg) {
 state.FUN_0027af00();
 state.FUN_0027af60(0,0);
 state.value=0;
 state.handle=FUN_002673a0(0,0);
 state.extra=0;
 state.flag=0;
 state.limit=999;
 argument=arg;
 f88=0;
 f324=0; f328=0; f32c=0; f330=0;
 fd0=0; f98=0; f9c=0; f8c=0;
 fc0=0; fcc=0; fc4=0; fc8=0;
 f334=1.0f;
 DAT_004e3760=this;
 return this;
}