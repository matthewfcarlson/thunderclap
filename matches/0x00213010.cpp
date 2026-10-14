typedef unsigned int U_213010;
extern U_213010 zero_213010;
U_213010* __fastcall helper(U_213010, U_213010);
U_213010 __cdecl combine(U_213010*, U_213010*);
U_213010 __cdecl target(U_213010 a, U_213010 b, U_213010 c) {
    U_213010* x = helper(b, a);
    U_213010* y = helper(c, a);
    if (x != &zero_213010 && y != &zero_213010)
        return combine(x, y);
    return 0;
}