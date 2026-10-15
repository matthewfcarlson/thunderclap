struct Pair {
    int a, b;
};
struct Sub {
    int q, r;
    void Set(int, int);
};
struct Obj {
    char pad0[8];
    int a;
    float f;
    int zero;
    char flag;
    char pad1[3];
    Sub sub;
    int other;
    float old;
    void Fn(int, Pair*, int, float);
};
void Obj::Fn(int x, Pair* p, int y, float z) {
    f -= old;
    a = x;
    zero = 0;
    flag = 1;
    other = y;
    old = z;
    if (p)
        sub.Set(p->a, p->b);
    else
        sub.Set(0, 0);
}