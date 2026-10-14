// cl-flags: /O2 /GR /GX
extern "C" int* g_table;

class CClearCollisionStun {
  public:
    virtual int vfunc_0(int x);
    virtual int vfunc_1();
    virtual int vfunc_2();
    virtual int vfunc_3();
    virtual int vfunc_4();
    virtual int vfunc_5();
    virtual int vfunc_6();
    virtual int vfunc_7();
    virtual int vfunc_8();
    virtual int vfunc_9();
    virtual int vfunc_10();
    virtual int vfunc_11();
    virtual int vfunc_12();
    virtual int vfunc_13();
};

int CClearCollisionStun::vfunc_0(int x) {
    return g_table[x];
}
