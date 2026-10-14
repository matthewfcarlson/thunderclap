class FELayout {
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
    virtual void f18();
    virtual void f19();
    virtual void f20();
};
class VScroll : public FELayout {
  public:
    char pad[0x3c];
    int* items;
    char pad2[0x1fc];
    int count;
    virtual void g0();
    virtual void g1();
    virtual void g2();
    virtual void g3();
    virtual void g4();
    virtual void g5();
    virtual void g6();
    virtual void g7();
    virtual void g8();
    virtual void f11();
};
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
    virtual void o();
};
extern char typeA_e27b0;
extern char typeB_e27b0;
void* cast(void*, int, void*, void*, int);
void VScroll::f11() {
    int i = 0;
    if (count > 0) {
        char* p = (char*)this + 0x40;
        do {
            int* q = (int*)cast((void*)*(int*)p, 0, &typeB_e27b0, &typeA_e27b0, 0);
            if (q)
                ((FEControl*)q)->o();
            ++i;
            p += 0x10;
        } while (i < count);
    }
}