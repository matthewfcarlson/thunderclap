typedef unsigned char u8;
struct Helper { void f(); };
struct PathLocatorTestCondition { char pad[8]; void *field_c; virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual PathLocatorTestCondition * vfunc_5(u8); virtual void vfunc_6(); };
extern void __cdecl thunk_FUN_00267090(void *);
extern char g_vft;
PathLocatorTestCondition *PathLocatorTestCondition::vfunc_5(u8 param) { *(void**)this=&g_vft; thunk_FUN_00267090(field_c); ((Helper*)this)->f(); if(param & 1) thunk_FUN_00267090(this); return this; }