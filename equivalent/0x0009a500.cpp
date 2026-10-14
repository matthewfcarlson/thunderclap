// STATUS: equivalent (tools/equiv.py level 3: 3009 inputs, branch coverage 16/16)
// FUN_0009a500 @ 0x0009a500
struct Mode { int FUN_00088fa0(); };
struct Context { char pad[0x80]; Mode mode; };
struct Manager { Context* FUN_00086310(); };
struct Global { char pad[0x54]; Manager* manager; };
extern Global* DAT_004dd700;
struct Receiver { void FUN_000a2c60(float,float); };
struct Object { char pad[0xb8]; Receiver* receiver; void target(float a,float b); };
void Object::target(float a,float b) {
 Context* context=DAT_004dd700->manager->FUN_00086310();
 if(context->mode.FUN_00088fa0()!=10) return;
 Receiver* r=receiver;
 if(!r) return;
 if(!(a>=30.0f && a<=120.0f)) a=(a>120.0f)?120.0f:30.0f;
 if(!(b>=0.0f && b<=10.0f)) b=(b>10.0f)?10.0f:0.0f;
 r->FUN_000a2c60(a,b);
}