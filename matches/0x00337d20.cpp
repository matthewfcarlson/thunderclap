extern int vtable;
struct X { void* v; int a; int b; int c; X(int p, int q); };
X::X(int p, int q) { v = &vtable; a = p; b = q; c = p; }