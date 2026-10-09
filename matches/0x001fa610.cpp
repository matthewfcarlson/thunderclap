struct V { virtual void f0(); virtual void f1(); };
class C { public: char pad[0x18]; V* p; void target(); };
void cb();
void __stdcall helper(void*, void*);
void C::target() { helper((void*)cb, this); p->f1(); }
