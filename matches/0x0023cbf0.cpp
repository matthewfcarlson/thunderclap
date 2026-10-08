namespace fight {

class Param {
public:
    virtual void pfunc_1();
    virtual void pfunc_2();
    virtual void pfunc_4();
};

class Condition {
public:
    virtual void cfunc_0();
    virtual void cfunc_3();
};

class PlatformCondition : public Condition, public Param {
public:
    virtual void vfunc_0();
    virtual void vfunc_5();
    virtual unsigned char vfunc_6(int, int, int);
    char mPad[0x0d - 0x08];
    char mFlag;
};

}

unsigned char fight::PlatformCondition::vfunc_6(int, int, int) {
    return mFlag;
}
