struct Ref_174fb0 {
    virtual void f();
    virtual void g();
};
struct Sub_174fb0 {
    void Init();
    char d[8];
};
class Action_174fb0 {
  public:
    Action_174fb0();
    virtual void v0();
    char pad[0x18];
};
class DriftToPositionAction_174fb0 : public Action_174fb0 {
  public:
    int a;
    Ref_174fb0* r;
    char flag24;
    char p25[3];
    char p28[0xc];
    int f34;
    Sub_174fb0 sub;
    int f40;
    int f44;
    int f48;
    int f4c;
    char f50;
    char f51;
    char f52;
    DriftToPositionAction_174fb0(int x, Ref_174fb0* p);
    virtual void v0();
};
DriftToPositionAction_174fb0::DriftToPositionAction_174fb0(int x, Ref_174fb0* p) {
    a = 0;
    r = 0;
    flag24 = 1;
    f34 = 0;
    sub.Init();
    f50 = 0;
    f51 = 0;
    f4c = 0;
    f40 = 0;
    f44 = 0;
    f48 = 0;
    f52 = 0;
    a = x;
    if (p)
        p->f();
    if (r)
        r->g();
    r = p;
}
