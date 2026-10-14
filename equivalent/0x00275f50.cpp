// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// core::File::vfunc_5 @ 0x00275f50
namespace core { struct File; }
struct Adapter {
 Adapter* FUN_00275390(core::File*, unsigned int);
};
extern void* __cdecl FUN_00273560(unsigned int);
struct Sink_275f50 { void FUN_00272b60(Adapter*, unsigned int, unsigned int); };
namespace core {
struct File {
 virtual void vfunc_0();
 virtual void vfunc_1();
 virtual void vfunc_2();
 virtual void vfunc_3();
 virtual void vfunc_4();
 virtual void vfunc_5(unsigned int arg);
 char padding[8];
 Sink_275f50* sink;
 unsigned int value;
};
void File::vfunc_5(unsigned int arg) {
 Adapter* allocation = static_cast<Adapter*>(FUN_00273560(16));
 Adapter* result = 0;
 if (allocation) result = allocation->FUN_00275390(this, arg);
 sink->FUN_00272b60(result, value, 0);
}
}