struct Param {
    int a;
    void finish();
};
struct Two {
    volatile unsigned char a, b;
};
struct Temp {
    int a;
    int pad0;
    unsigned char c, d;
    char pad1[6];
    short b;
    char tail[6];
    void init(Param*);
    void finish();
};
struct Out {
    char data[8];
};
struct Mgr {
    void fn(Out*, Temp*);
};
struct Owner {
    char pad[0xc6c];
    Mgr* mgr;
    void target(Param x, int y, Two z, int w, short v);
};
void Owner::target(Param x, int y, Two z, int w, short v) {
    Temp t;
    t.init(&x);
    t.c = z.a;
    t.d = z.b;
    t.b = v;
    Out o;
    mgr->fn(&o, &t);
    t.finish();
    x.finish();
}