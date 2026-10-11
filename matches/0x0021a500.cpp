extern "C" char DAT_00426824[];
typedef unsigned int U;
extern U __cdecl FUN_00219e50(U, U);
extern void __cdecl FUN_0021a3e0(U, U, U*);
void __cdecl target(U a, U b, U c) {
    U local[2];
    if (FUN_00219e50(b, c) == ((int)DAT_00426824)) {
        local[1] = c;
        local[0] = 4;
        FUN_0021a3e0(a, b, local);
    }
}