extern int gA, gB, gC;
extern "C" int __stdcall inner(int);
extern "C" int __cdecl outer(int, int, int*, int*, int);
int __stdcall FUN_000e75a0(int x) {
    return outer(outer(inner(x), 0, &gC, &gB, 0), 0, &gB, &gA, 0);
}