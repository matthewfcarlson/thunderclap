extern "C" char DAT_003f3e88[];
struct Caster {
    int* v;
};
struct Host {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d(Caster*, int, int);
    void run(int, int);
};
void Host::run(int x, int y) {
    Caster c;
    c.v = (int*)((int)DAT_003f3e88);
    d(&c, x, y);
}