// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// om::MetaTypeAttrib<float>::vfunc_1 @ 0x0024d790
namespace om { struct MetaTypeAttribBase { virtual void vfunc_0(); virtual int vfunc_1(void *, int); virtual void vfunc_2(); virtual void vfunc_3(); char pad[16]; char *values; }; struct MetaTypeAttribFloat : MetaTypeAttribBase { int vfunc_1(void *destination, int offset); }; }
int __cdecl FUN_0025abf0(void *destination, unsigned int value);
int om::MetaTypeAttribFloat::vfunc_1(void *destination, int offset) { return FUN_0025abf0(destination, *(unsigned int *)(values + offset)); }