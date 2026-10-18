struct Obj_2139f0 {
    char p0[8];
    int a;
    char p1[16];
    int b;
};
struct Pair_2139f0 {
    int a;
    int z;
};
int __fastcall calc(int x, Obj_2139f0* o);
int __cdecl process(Obj_2139f0*, void*, Pair_2139f0*, int, int);
extern "C" char marker;
int __cdecl target(Obj_2139f0* o, int n, int v, int x) {
    int t;
    if (x == 0)
        t = 0;
    else
        t = calc(x, o) - o->b;
    Pair_2139f0 p;
    p.a = o->a - (n * 8 + 8);
    p.z = v;
    return process(o, &marker, &p, p.a - o->b, t);
}