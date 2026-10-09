typedef unsigned int U;
U __cdecl First(U);
void __cdecl Second(U, U);
void __cdecl Target(U x) { U y = First(x); Second(x, y); }