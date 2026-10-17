// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// om::MetaTypeAttrib<int>::vfunc_1 @ 0x0024d720
namespace om { struct MetaTypeAttribBase { virtual void vfunc_0(); virtual void vfunc_1(int, int); virtual void vfunc_2(); virtual void vfunc_3(); char pad[16]; int* values; }; struct MetaTypeAttrib : MetaTypeAttribBase { void vfunc_1(int destination, int offset); }; }
void __cdecl FUN_0025ab30(int, int);
void om::MetaTypeAttrib::vfunc_1(int destination, int offset) { FUN_0025ab30(destination, *(int*)((char*)values + offset)); }