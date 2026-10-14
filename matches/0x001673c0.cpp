struct ObjEnd {
    char pad[0x1b28];
    int field;
};
struct ObjMid {
    ObjEnd* Call2();
};
struct ObjA_1673c0 {
    ObjMid* Call1();
};

class RageModeStateCondition {
  public:
    virtual void vfunc_0();
    virtual void p_vfunc_1();
    virtual void p_vfunc_2();
    virtual void c_vfunc_3();
    virtual void p_vfunc_4();
    virtual void vfunc_5();
    virtual bool vfunc_6(int a, int b, int c);
    char pad0[8];
    int mode;
    int other;
};

bool RageModeStateCondition::vfunc_6(int a, int b, int c) {
    ObjMid* m = ((ObjA_1673c0*)b)->Call1();
    ObjEnd* e = m->Call2();
    int v = e->field;
    switch (mode) {
    case 0:
        return v == other;
    case 1:
        return v != other;
    default:
        return false;
    }
}
