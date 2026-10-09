class VScroll {
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
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void vfunc_18(void*);
    virtual void f19();
    virtual void f20();
    virtual void f21();
    char pad[0x240 - 4];
    int count;
    int selected;
    char pad2[0x268 - 0x248];
    int changes;
};
extern int __cdecl FUN_00344e74(int, int, const char*, const char*, int);
void VScroll::vfunc_18(void* item) {
    if (count < 0x20) {
        ((int*)((char*)this + (count + 4) * 16))[0] = (int)item;
        ((int*)((char*)this + 0x48 + count * 16))[0] = 0;
        if (!selected) {
            if (FUN_00344e74(((int*)((char*)this + (count + 4) * 16))[0], 0, (const char*)0x49dba4,
                             (const char*)0x49f4f0, 0))
                selected = FUN_00344e74(((int*)((char*)this + (count + 4) * 16))[0], 0, (const char*)0x49dba4,
                                        (const char*)0x49f4f0, 0);
        }
        ++count;
        if (count > 1)
            ++changes;
    }
}