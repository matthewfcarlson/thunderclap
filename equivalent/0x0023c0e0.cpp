// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 2/2)
// fight::BinReader::vfunc_13 @ 0x0023c0e0
namespace fight {
class BinReader {
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2();
    virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5();
    virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8();
    virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual int vfunc_13();
    virtual void vfunc_14(); virtual void vfunc_15(); virtual void vfunc_16();
    virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
    char padding[0x24];
    int field28;
    int field2c;
};
}
struct ThisCall_0023bb90 {
    void FUN_0023bb90();
};
int fight::BinReader::vfunc_13() {
    ((ThisCall_0023bb90*)(this))->FUN_0023bb90();
    return (field28 | field2c) != 0;
}