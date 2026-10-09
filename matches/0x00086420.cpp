struct A {
    void f();
};
struct B {
    void g();
};
struct Hub {
    char pad[0x10];
    A* a;
    char pad2[4];
    B* b;
};
struct Manager {
    char pad[0x54];
    Hub* hub;
};
extern Manager* gManager;
struct Target {
    int value;
    void run(int);
};
void Target::run(int v) {
    value = v;
    if (v == 1)
        gManager->hub->a->f();
    gManager->hub->b->g();
}
