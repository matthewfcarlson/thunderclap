struct A_86420 {
    void f();
};
struct B_86420 {
    void g();
};
struct Hub_86420 {
    char pad[0x10];
    A_86420* a;
    char pad2[4];
    B_86420* b;
};
struct Manager_86420 {
    char pad[0x54];
    Hub_86420* hub;
};
extern Manager_86420* gManager_86420;
struct Target_86420 {
    int value;
    void run(int);
};
void Target_86420::run(int v) {
    value = v;
    if (v == 1)
        gManager_86420->hub->a->f();
    gManager_86420->hub->b->g();
}
