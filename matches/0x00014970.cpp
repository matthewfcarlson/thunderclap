// Same code shape as 0x00014890 (propagated; names are from that function)
class H1 { public: void* f1(); };
class H2 { public: void* f2(); };
class H3 { public: bool f3(void*); };

class CProceduralDurationAnimationAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual bool vfunc_8(int);
    char pad[0x1c - 4];
    void* mAt1c;
    void* mAt20;
    void* mAt24;
};

bool CProceduralDurationAnimationAction::vfunc_8(int) {
    void* x = ((H1*)mAt1c)->f1();
    void* y = ((H2*)x)->f2();
    bool r;
    if (y == 0) r = true;
    else r = ((H3*)y)->f3(mAt24);
    return !r;
}
