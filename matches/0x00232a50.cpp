class Obj { public: virtual void f0(); virtual void f1(); };
void __cdecl thunk(void*);
class Target { public: Obj* m; Target* f(unsigned char flags); };
Target* Target::f(unsigned char flags) { if (m) { m->f1(); m = 0; } if (flags & 1) thunk(this); return this; }