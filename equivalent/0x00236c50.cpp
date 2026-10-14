// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// fight::Track::vfunc_3 @ 0x00236c50
extern unsigned int DAT_004ca290;
extern unsigned int DAT_004ca294;

unsigned __int64 __cdecl FUN_002672f0(unsigned int name, int a, int b);

class Param {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual bool vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10(unsigned __int64 id, int *out);
    virtual void vfunc_11(unsigned __int64 id, char *out);
    virtual void vfunc_12();
    virtual bool vfunc_13();
    virtual unsigned __int64 vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16(unsigned __int64 id);
    virtual void vfunc_17();
};

// The incoming argument slot doubles as an output byte.
union ParamArg_236c50 {
    Param *param;
    char flag;
};

class Track {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual bool vfunc_3(unsigned __int64 id, int extra, ParamArg_236c50 arg);
    virtual void vfunc_4(int extra, Param *param);
    char pad04[4];
    int value;              // 0x8
};

bool Track::vfunc_3(unsigned __int64 id, int extra, ParamArg_236c50 arg)
{
    Param *param = arg.param;
    int count;

    if (!param->vfunc_13())
        return false;
    unsigned __int64 key = param->vfunc_14();
    if (key != id)
        return false;

    param->vfunc_16(key);
    if (!param->vfunc_3()) {
        arg.flag = 0;
        param->vfunc_11(FUN_002672f0(DAT_004ca290, 0, 0), &arg.flag);
    }
    count = 0;
    param->vfunc_10(FUN_002672f0(DAT_004ca294, 0, 0), &count);
    value = count;
    vfunc_4(extra, param);
    param->vfunc_17();
    return true;
}
