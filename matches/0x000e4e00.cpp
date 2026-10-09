class FEContainer {
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
    virtual void vfunc_18(int, int);
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    char pad[0x48];
    int slots[128];
};
void FEContainer::vfunc_18(int item, int index) {
    if (!item)
        return;
    if (index >= 128)
        return;
    int found = 0;
    int* p = slots + 1;
    while (found < 128) {
        if (p[-1] == item)
            break;
        if (p[0] == item) {
            ++found;
            break;
        }
        if (p[1] == item) {
            found += 2;
            break;
        }
        if (p[2] == item) {
            found += 3;
            break;
        }
        found += 4;
        p += 4;
    }
    if (found >= 128)
        return;
    int tmp = slots[index];
    slots[index] = item;
    slots[found] = tmp;
}