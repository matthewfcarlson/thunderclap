extern "C" char DAT_003f3e88[];
struct Caster_22960 {
    int* v;
};
struct Host_22960 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d(Caster_22960*, int, int);
    void run(int, int);
};
void Host_22960::run(int x, int y) {
    Caster_22960 c;
    c.v = (int*)((int)DAT_003f3e88);
    d(&c, x, y);
}