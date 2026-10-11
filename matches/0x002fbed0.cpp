extern "C" char DAT_004317dc[];
class Part {
  public:
    void Init();
};
class Obj {
  public:
    virtual void v();
    char pad[0x38];
    Part p1;
    char pad2[0x3f];
    Part p2;
    void Base();
    void Build(int, int, int, int, int);
    Obj* Target(int, int, int, int, int);
};
Obj* Obj::Target(int a, int b, int c, int d, int e) {
    Base();
    *(int*)this = ((int)DAT_004317dc);
    p1.Init();
    p2.Init();
    Build(a, b, c, d, e);
    return this;
}
