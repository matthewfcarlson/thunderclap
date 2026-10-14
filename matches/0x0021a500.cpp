extern "C" char DAT_00426824[];
typedef unsigned int U_21a500;
extern U_21a500 __cdecl FUN_00219e50(U_21a500, U_21a500);
extern void __cdecl FUN_0021a3e0(U_21a500, U_21a500, U_21a500*);
void __cdecl target(U_21a500 a, U_21a500 b, U_21a500 c) {
    U_21a500 local[2];
    if (FUN_00219e50(b, c) == ((int)DAT_00426824)) {
        local[1] = c;
        local[0] = 4;
        FUN_0021a3e0(a, b, local);
    }
}