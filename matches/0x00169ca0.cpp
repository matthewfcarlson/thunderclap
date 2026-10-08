struct ParamValue {
    char pad[0x10];
};

struct ParamValueEnum : ParamValue {
};

struct ParamEnumConstList : ParamValueEnum {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual int GetCount(int arg);
    virtual void vfunc_8();

    int mCount; // offset 0x14
};

int ParamEnumConstList::GetCount(int arg) {
    return mCount;
}
