class Inner {
  public:
    virtual int f0();
    virtual int f1();
    virtual int f2();
    virtual int f3();
    virtual int f4();
    virtual int f5();
    virtual bool f6(int, int);
};
class FEContainer {
  public:
    virtual int f0();
    virtual int f1();
    virtual bool vfunc_2(int, int);
    virtual int f3();
    virtual int f4();
    virtual int f5();
    virtual int f6();
    virtual int f7();
    virtual int f8();
    virtual int f9();
    virtual int f10();
    virtual int f11();
    virtual int f12();
    virtual int f13();
    virtual int f14();
    virtual int f15();
    virtual int f16();
    virtual int f17();
    virtual int f18();
    virtual int f19();
    virtual int f20();
    virtual int f21();
    virtual int f22();
    virtual int f23();
    virtual int f24();
    virtual int f25();
    virtual int f26();
    virtual int f27();
    virtual int f28();
    virtual int f29();
    virtual int f30();
    virtual int f31();
    virtual int f32();
    virtual int f33();
    virtual int f34();
    virtual int f35();
    virtual int f36();
    virtual int f37();
    virtual int f38();
    virtual int f39();
    virtual int f40();
    virtual int f41();
    virtual int f42();
    virtual int f43();
    virtual int f44();
    virtual int f45();
    virtual int f46();
    virtual int f47();
    virtual int f48();
    virtual int f49();
    virtual int f50();
    virtual int f51();
    virtual int f52();
    char pad[0x44];
    Inner* obj;
    char pad2[0x808];
    int index;
};
bool FEContainer::vfunc_2(int a, int b) {
    if ((index == -1 || index == b) && obj != 0)
        return obj->f6(a, b);
    return false;
}