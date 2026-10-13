// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 18/18)
// FUN_002fc740 @ 0x002fc740
struct Ref { virtual void AddRef(); virtual void Release(); char pad[8]; void* data; Ref* FUN_00310080(void*,int,void*); void FUN_0030ff80(int); };
struct Input { char pad[12]; void* data; void FUN_00284820(int); };
extern char DAT_004c60bc; extern char DAT_004d2d90;
void* __cdecl FUN_00344e74(void*,int,void*,void*,int);
void* __cdecl FUN_0008d690(unsigned);
Ref* __cdecl FUN_002fddf0(void*,void*,void*);
Ref* __cdecl FUN_002efa90(void*,void*,int);
Ref* __cdecl FUN_002fe480(Input*,void*,void*);
namespace physics { struct PhysicsInstance { virtual void v0(); unsigned field4; unsigned field8; unsigned char active; char pad[3]; Ref* object; Ref* wrapper; PhysicsInstance(void*,void*,Input*,unsigned char); void FUN_002fc420(); }; }
physics::PhysicsInstance::PhysicsInstance(void* a,void* b,Input* input,unsigned char mode) {
field4=0; active=1; object=0; wrapper=0;
Ref* result;
if (!mode) { if(input) {
void* cast=FUN_00344e74(b,0,&DAT_004c60bc,&DAT_004d2d90,0);
Ref* mem=(Ref*)FUN_0008d690(32);
Ref* fresh=mem?mem->FUN_00310080(input,2,input->data):0;
Ref* old=wrapper;
if(old!=fresh){ wrapper=fresh; if(fresh)fresh->AddRef(); if(old)old->Release(); }
wrapper->AddRef(); wrapper->FUN_0030ff80(1);
result=FUN_002fddf0(wrapper->data,a,cast);
} else result=FUN_002efa90(a,b,0);
} else { input->FUN_00284820(0); result=FUN_002fe480(input,a,b); }
Ref* old=object;
if(old!=result){object=result;if(result)result->AddRef();if(old)old->Release();}
FUN_002fc420();
}
