struct Obj {
    char p0[8];
    int a;
    char p1[16];
    int b;
};
struct Pair {
    int a;
    int z;
};
int __fastcall calc(int x, Obj* o);
void __cdecl process(Obj*, void*, Pair*, int, int);
extern "C" char marker;
void __cdecl target(Obj* o, int n, int v, int x) {
    int t;
    if (x == 0)
        t = 0;
    else
        t = calc(x, o) - o->b;
    Pair p;
    p.a = o->a - (n * 8 + 8);
    p.z = v;
    process(o, &marker, &p, p.a - o->b, t);
}