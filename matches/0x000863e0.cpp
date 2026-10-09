struct Inner {
    char pad[0x18];
    void f();
};
struct Mid {
    char pad[0x18];
    Inner* p;
};
struct Root {
    char pad[0x54];
    Mid* p;
};
extern Root* g;
struct Target {
    unsigned int a;
    char pad[4];
    unsigned int b;
    void run(unsigned int x);
};
void Target::run(unsigned int x) {
    b = a;
    a = x;
    g->p->p->f();
}