typedef unsigned int U;
extern U g;
extern U __cdecl lookup(U, U);
struct Obj { U run(U, U, U); };
U __cdecl target(U a, U b, U c) {
    g = b;
    U x = lookup(b, 0x4a4);
    if (x) return ((Obj*)x)->run(a, b, c);
    return 0;
}