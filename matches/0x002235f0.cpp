extern "C" char DAT_004272b8[];
struct Sub {
    char pad[0x54];
    void init();
};
struct Puppet {
    void* vt;
    char pad[0xc];
    Sub sub;
    int a, b;
    void baseInit();
    void finish(int);
    Puppet* ctor(int arg);
};
Puppet* Puppet::ctor(int arg) {
    baseInit();
    vt = (void*)((int)DAT_004272b8);
    sub.init();
    a = 0;
    b = 0;
    finish(arg);
    return this;
}
