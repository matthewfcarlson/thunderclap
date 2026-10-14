struct Param {
    int a;
    void finish();
};
struct Two_1f96b0 {
    volatile unsigned char a, b;
};
struct Temp_1f96b0 {
    int a;
    int pad0;
    unsigned char c, d;
    char pad1[6];
    short b;
    char tail[6];
    void init(Param*);
    void finish();
};
struct Out_1f96b0 {
    char data[8];
};
struct Mgr_1f96b0 {
    void fn(Out_1f96b0*, Temp_1f96b0*);
};
struct Owner_1f96b0 {
    char pad[0xc6c];
    Mgr_1f96b0* mgr;
    void target(Param x, int y, Two_1f96b0 z, int w, short v);
};
void Owner_1f96b0::target(Param x, int y, Two_1f96b0 z, int w, short v) {
    Temp_1f96b0 t;
    t.init(&x);
    t.c = z.a;
    t.d = z.b;
    t.b = v;
    Out_1f96b0 o;
    mgr->fn(&o, &t);
    t.finish();
    x.finish();
}