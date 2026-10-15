class Item {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8(int, int);
};
class FEDialog {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    char pad[0x24c - 4];
    Item* items[0x80];
    char pad2[0x9a4 - 0x24c - 0x200];
    Item* current;
    char active;
};
void FEDialog::vfunc_11() {
    if (active) {
        if (current)
            current->f8(0, 0);
        for (int i = 0; i < 0x80; ++i) {
            if (!items[i])
                return;
            items[i]->f2();
        }
    }
}