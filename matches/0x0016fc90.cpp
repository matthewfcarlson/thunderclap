class Obj {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(void*, int, int);
};
class Thing {
  public:
    char pad[0x10];
    Obj* m;
    char pad2[0x84];
    int FUN(int arg);
};
int Thing::FUN(int arg) {
    m->v8((char*)this + 0x98, arg, -1);
    return arg;
}