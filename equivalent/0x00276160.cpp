// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// core::File::vfunc_18 @ 0x00276160
namespace core { struct File; }
struct Result_276160 { unsigned int FUN_00274ca0(void* node, core::File* file, unsigned int a, unsigned int b); };
struct Sink_276160 { void FUN_00272b60(unsigned int value, unsigned int context, unsigned int flags); };
extern Result_276160* __cdecl FUN_00273560(unsigned int size);
extern void* __cdecl FUN_0026dbb0();
namespace core {
struct File {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
 virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
 virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
 virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
 virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(unsigned int a,unsigned int b);
 char bases[8];
 Sink_276160* sink;
 unsigned int context;
};
void File::vfunc_18(unsigned int a, unsigned int b) {
 Result_276160* result = FUN_00273560(24);
 unsigned int value = 0;
 if (result) {
  value = result->FUN_00274ca0(FUN_0026dbb0(), this, a, b);
 }
 sink->FUN_00272b60(value,context,0);
}
}
