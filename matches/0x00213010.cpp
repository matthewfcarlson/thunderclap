typedef unsigned int U;
extern U zero;
U* __fastcall helper(U, U);
U __cdecl combine(U*, U*);
U __cdecl target(U a, U b, U c) {
    U* x = helper(b, a);
    U* y = helper(c, a);
    if (x != &zero && y != &zero) return combine(x, y);
    return 0;
}