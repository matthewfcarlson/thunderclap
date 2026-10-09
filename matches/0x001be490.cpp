class Inner { public: char pad0[8]; int a; char b; char padD[3]; int c; int d; char pad18[4]; short f; };
class Outer { public: char pad0[0x2c]; Inner* p; char pad30[0x20]; int q; void Reset(); };
void Outer::Reset() { Inner* x = p; q = 0; x->b = 0; x->c = 0; x->a = 0; x->d = 0; x->f = 0; }