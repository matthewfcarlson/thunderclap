class Obj_16fc90 {
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
class Thing_16fc90 {
  public:
    char pad[0x10];
    Obj_16fc90* m;
    char pad2[0x84];
    int FUN(int arg);
};
int Thing_16fc90::FUN(int arg) {
    m->v8((char*)this + 0x98, arg, -1);
    return arg;
}