struct Type { virtual void f0(); virtual void vfunc_1(); };
extern "C" void __cdecl helper(void*, Type*);
void Type::vfunc_1() { helper((void*)0x4cd1a8, this); }