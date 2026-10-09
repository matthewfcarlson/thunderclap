class MemoryDlAllocator {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(int);
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    char pad[0x498];
    unsigned char flag;
    unsigned char flag2;
    char pad2[2];
    int count;
    void target();
};
void cleanup(int);
void MemoryDlAllocator::target() {
    if (count == 1) {
        if (flag == 1)
            cleanup(*(int*)((char*)this + 0xc));
        if (flag2 == 0)
            vfunc_2(1);
        else
            vfunc_2(0);
    } else
        --count;
}