struct Pair {
    int a, b;
};
struct Obj {
    char pad[12];
    int kind;
    char flag;
    char pad2[3];
    int val;
    Pair pair;
    int zero;
    float f;
    int other;
};
void __cdecl target(int unused, Obj* o, char c, int v, Pair* p) {
    o->flag = c;
    o->val = v;
    o->kind = 3;
    if (p)
        o->pair = *p;
    else {
        o->pair.a = 0;
        o->pair.b = 0;
    }
    o->other = 0;
    o->zero = 0;
    if (!o->pair.b) {
        o->f = 1.0f;
        return;
    }
    o->f = 0.0f;
}