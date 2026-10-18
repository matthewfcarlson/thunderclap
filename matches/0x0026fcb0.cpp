class XboxDrive {
  public:
    virtual int vfunc_0();
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
    virtual int vfunc_14();
    char pad[0xb4 - 4];
    unsigned int field_b4;
    char pad2[4];
    unsigned char flags;
    unsigned int helper(unsigned int);
};
extern int XFormatUtilityDrive();
extern unsigned int __stdcall GetLastError();
int XboxDrive::vfunc_14() {
    if ((flags & 8) != 0) {
        if (XFormatUtilityDrive() == 0)
            field_b4 = helper(GetLastError());
    }
    field_b4 = 0;
    return 1;
}