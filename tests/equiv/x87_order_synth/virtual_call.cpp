// MSVC calls a virtual function through `call [vtable+n]`, clang through a register loaded from it: the same call.
// ref-msvc
// expect: clean=1 round=1
struct B { virtual float get(); virtual float get2(); };
extern "C" float ref(B* b) { return b->get() * 2.0f + b->get2(); }
extern "C" float test(B* b) { return b->get() * 2.0f + b->get2(); }
