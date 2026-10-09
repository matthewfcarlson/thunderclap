struct A { int f(unsigned long long); int target(int p); };
extern unsigned long long __cdecl FUN_0027b020(int);
int A::target(int p) { int r = f(FUN_0027b020(p)); if (r != -1) return r; return r | r; }
