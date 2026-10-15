extern int __stdcall Inner(int);
extern int __cdecl Combine(int, int, void*, void*, int);
extern char a, b, c;
int __stdcall Target(int x) {
    return Combine(Combine(Inner(x), 0, &a, &b, 0), 0, &b, &c, 0);
}