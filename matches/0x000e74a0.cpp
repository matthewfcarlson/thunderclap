extern int a, b, c;
int __stdcall inner(int);
int __cdecl outer(int, int, int*, int*, int);
int __stdcall target(int x) {
    return outer(outer(inner(x), 0, &c, &b, 0), 0, &b, &a, 0);
}