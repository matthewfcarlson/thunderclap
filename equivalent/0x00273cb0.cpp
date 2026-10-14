// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// core::SaveGameOpenRequest::vfunc_1 @ 0x00273cb0
struct Info_273cb0 { char pad[12]; unsigned value; };
struct Backend_273cb0 {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8();
 virtual int open(char*,unsigned,unsigned,unsigned,unsigned,void*,void*);
 Info_273cb0* FUN_002728d0();
 unsigned FUN_00272880();
};
struct Lock_273cb0 { virtual void lock(); virtual void unlock(); };
struct State_273cb0 {
 unsigned unknown0;
 Lock_273cb0 guard;
 unsigned unknown8;
 Backend_273cb0* backend;
 unsigned unknown10;
 unsigned status;
 char pad18[4];
 unsigned char opened;
 char pad1d;
 char name[0x128-0x1e];
 char data128[0x15c-0x128];
 unsigned data15c;
 unsigned data160;
 unsigned value164;
};
namespace core {
struct SaveGameOpenRequest {
 virtual void vfunc_0();
 virtual int vfunc_1();
 virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6();
 unsigned unknown4;
 State_273cb0* state;
 unsigned argC;
 unsigned char arg10;
 char padding[3];
 unsigned arg14;
 unsigned arg18;
};
int SaveGameOpenRequest::vfunc_1() {
 State_273cb0* s = state;
 Backend_273cb0* backend = s->backend;
 int result = backend->open(s->name,argC,arg10,arg14,arg18,&s->data15c,s->data128);
 if(result == 1) {
 state->opened = 1;
 Info_273cb0* info = backend->FUN_002728d0();
 state->value164 = info->value;
 }
 unsigned status = backend->FUN_00272880();
 state->guard.lock();
 state->status = status;
 state->guard.unlock();
 return result;
}
}