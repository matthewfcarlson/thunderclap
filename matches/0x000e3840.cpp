class Provider {
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
    virtual int get();
};
struct Middle {
    char pad[4];
    Provider* provider;
};
struct Outer {
    char pad[8];
    Middle* middle;
};
class Elem {
    char pad[0x38];

  public:
    int get(int, int);
};
extern "C" void __cdecl finish(int, int, int);
class Obj {
    char pad[0x14];
    Outer* outer;
    char pad2[0x140];
    Elem elements[1];

  public:
    void work(int, int, int);
};
void Obj::work(int index, int a, int b) {
    int v = outer->middle->provider->get();
    finish(elements[index].get(v, 0), a, b);
}