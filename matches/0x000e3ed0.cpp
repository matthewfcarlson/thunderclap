class TextTable {
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
    virtual void vfunc_14(int);
    virtual void a15();
    virtual void a16();
    virtual void a17();
    virtual void a18();
    char pad[0x40];
    int f44;
    char p1[0x118 - 0x48];
    int f118;
    char p2[0x148 - 0x11c];
    int f148, f14c;
    TextTable* f150;
    TextTable* f154;
    TextTable* f158;
};
void TextTable::vfunc_14(int) {
    int v = f44;
    TextTable* p = f150;
    f148 = v;
    if (p)
        p->f44 = v;
    TextTable* a = f154;
    if (a && f158) {
        a->f118 = 0;
        f158->f118 = 0;
    }
}