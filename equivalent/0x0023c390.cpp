// STATUS: equivalent (tools/equiv.py level 3: 3005 inputs, branch coverage 12/12)
// fight::Reference::vfunc_8 @ 0x0023c390
namespace fight {

class Reference {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual int vfunc_8(unsigned int a, unsigned int b);
    virtual void vfunc_9();
    char pad04[0x24];
    Reference *child;
    char FUN_002333f0(unsigned int a, unsigned int b);
};

extern Reference *DAT_004e5c40;

int Reference::vfunc_8(unsigned int a, unsigned int b)
{
    if (DAT_004e5c40 == 0) {
        DAT_004e5c40 = this;
    } else if (DAT_004e5c40 == this) {
        DAT_004e5c40 = 0;
        return 0;
    }
    if (FUN_002333f0(a, b) && child != 0) {
        int result = child->vfunc_8(a, b);
        if (DAT_004e5c40 == this)
            DAT_004e5c40 = 0;
        return result;
    }
    if (DAT_004e5c40 == this)
        DAT_004e5c40 = 0;
    return 0;
}

}
