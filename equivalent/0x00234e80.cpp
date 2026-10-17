// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// fight::ParamValueVector::vfunc_5 @ 0x00234e80
namespace fight {
struct ValueResult { unsigned first, second, third; };
struct Reader {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual char vfunc_5(unsigned, unsigned, ValueResult *);
};
struct ParamValueVector {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual char vfunc_5(unsigned, unsigned, Reader *);
    virtual void FUN_00344f51(unsigned, ValueResult *);
    unsigned reserved;
    unsigned field8;
    unsigned fieldC;
};
char ParamValueVector::vfunc_5(unsigned destination, unsigned, Reader *reader) {
    ValueResult result = {0, 0, 0};
    char success = reader->vfunc_5(field8, fieldC, &result);
    if (success)
        FUN_00344f51(destination, &result);
    return success;
}
}