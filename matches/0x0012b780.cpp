extern const char kRttiA[];
extern const char kRttiB[];
int CheckFn(int a, int b, const void* c, const void* d, int e);

class Obj2_12b780 {
  public:
    unsigned char Test(void* a, unsigned char b);
};
class Obj_12b780 {
  public:
    Obj_12b780* Get();
    Obj2_12b780* Next();
};

class ThreatCondition {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual bool vfunc_6(int a, int c, int d);
    char pad[8];
    unsigned char mA;
    char pad2[3];
    char mBlock[8];
    unsigned char mB;
};

bool ThreatCondition::vfunc_6(int a, int c, int d) {
    if (!CheckFn(c, 0, kRttiA, kRttiB, 0))
        return false;
    Obj_12b780* o = ((Obj_12b780*)c)->Get();
    Obj2_12b780* x = o->Next();
    unsigned char r = x->Test(mBlock, mB);
    unsigned char m = mA;
    return r == m;
}
