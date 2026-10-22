// An unsigned int converted to float: MSVC's fild + 2^32 fixup against clang's 64-bit fild.
// ref-msvc
// expect: clean=1
extern "C" unsigned int src_u(float* p);
extern "C" float ref(float* a) { return a[0] * (float)src_u(a); }
extern "C" float test(float* a) { return a[0] * (float)src_u(a); }
