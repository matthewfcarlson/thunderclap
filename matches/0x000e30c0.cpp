class FEControl {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void a14();
    virtual void a15();
    virtual void a16();
    virtual void a17();
    virtual void a18();
};
class TextSelector : public FEControl {
  public:
    char pad[0x150];
    int value;
    char pad2[0x1d94 - 0x158];
    void vfunc_25(int);
};
void __stdcall Notify(int);
void TextSelector::vfunc_25(int p) {
    if (value != p) {
        value = p;
        if (*(int*)((char*)this + 0x1d94))
            Notify(p);
        a0();
    }
}