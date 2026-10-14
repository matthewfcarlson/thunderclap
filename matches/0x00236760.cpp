struct Param {
    virtual void F();
    char pad[4];
    int a;
    int b;
};
struct Helper_236760 {
    void Run(int, int, Param*);
};
struct Owner_236760 {
    char pad[0x14];
    Helper_236760 helper;
    bool Target(Param* p);
};
bool Owner_236760::Target(Param* p) {
    int x = p->a;
    int y = p->b;
    p->F();
    helper.Run(x, y, p);
    return true;
}