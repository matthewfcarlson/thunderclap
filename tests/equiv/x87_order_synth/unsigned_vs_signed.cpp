// Negative: a signed conversion is not an unsigned one.
// ref-msvc
// expect: unmatched=1
extern "C" unsigned int src_u(float* p);
extern "C" float ref(float* a) { return a[0] * (float)src_u(a); }
extern "C" float test(float* a) { return a[0] * (float)(int)src_u(a); }
