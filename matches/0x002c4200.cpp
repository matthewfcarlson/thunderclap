class Thing { public: char pad[0x74]; int a; int b; int c; void Get(int* x, int* y, int* z); };
void Thing::Get(int* x, int* y, int* z) { *x = a; *y = b; *z = c; }