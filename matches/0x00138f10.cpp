// Same code shape as 0x001134e0 (propagated; names are from that function)
class KeywordWaitTrack {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual int vfunc_10(int a, int b, int c);
};
extern int FUN_00344e74(int, int, const void*, const void*, int);
extern void* FUN_0008d690(int);
extern int RTTI_Type1;
extern int RTTI_Type2;
class AllocObj_138f10 {
  public:
    int init(KeywordWaitTrack*, int);
};
int KeywordWaitTrack::vfunc_10(int a, int b, int c) {
    if (FUN_00344e74(c, 0, &RTTI_Type1, &RTTI_Type2, 0)) {
        AllocObj_138f10* p = (AllocObj_138f10*)FUN_0008d690(0x2c);
        if (p)
            return p->init(this, c);
    }
    return 0;
}