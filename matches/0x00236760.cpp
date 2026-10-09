struct Param {
    virtual void F();
    char pad[4];
    int a;
    int b;
};
struct Helper {
    void Run(int, int, Param*);
};
struct Owner {
    char pad[0x14];
    Helper helper;
    bool Target(Param* p);
};
bool Owner::Target(Param* p) {
    int x = p->a;
    int y = p->b;
    p->F();
    helper.Run(x, y, p);
    return true;
}