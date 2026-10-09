struct S {
    char p0[8];
    int a;
    char p1[0x10];
    int b;
    char p2[0x34];
    int c;
};
struct L {
    int a;
    int b;
    int c;
    int d;
    int e;
};
int FUN_00215de0(S*, void (*)(), L*, int, int);
void FUN_0021add0(S*, int, int, int);
void FUN_00215c00();
int G(S* s, int a, int b) {
    L l;
    l.a = a;
    l.e = b;
    l.b = 0;
    l.d = 0;
    int r = FUN_00215de0(s, FUN_00215c00, &l, s->a - s->b, s->c);
    FUN_0021add0(s, l.b, l.d, 0);
    return r;
}
