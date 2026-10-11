// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// core::DriveFindFirstRequest::vfunc_1 @ 0x002747d0
namespace core {
struct Lock { virtual void lock(); virtual void unlock(); };
struct Drive {
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17();
 virtual int find(void*, unsigned int, unsigned int*, bool);
 unsigned int FUN_00272880();
};
struct State { unsigned int unk; Lock lock; unsigned int unk8; Drive* drive; char pad[8]; unsigned int result; unsigned int handle; unsigned char active; };
struct DriveFindFirstRequest {
 virtual void vfunc_0(); virtual int vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6();
 unsigned int unk4; State* state; char buffer[0x104]; unsigned int flags;
};
int DriveFindFirstRequest::vfunc_1() {
 Drive* drive = state->drive;
 int result = drive->find(buffer, flags, &state->handle, state->active == 0);
 state->active = result == 1 ? 1 : 0;
 unsigned int status = drive->FUN_00272880();
 state->lock.lock();
 state->result = status;
 state->lock.unlock();
 return result;
}
}
