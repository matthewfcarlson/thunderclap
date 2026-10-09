// Same code shape as 0x000f95e0 (propagated; names are from that function)
typedef unsigned int U;
struct D { U f(U *out, int a, int b, int c); };
struct C { char pad[0x284]; D *member; U g(); };
U C::g() { U local; member->f(&local, 1, 4, 1); return local; }