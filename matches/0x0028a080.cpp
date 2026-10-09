class X { public: char pad[0x14]; short* a; int* b; void f(int i, float* out, int* out2); };
void X::f(int i, float* out, int* out2) { *out = (float)a[i]; *out2 = b[i]; }