class Condition {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual char vfunc_6(void*, void*, void*);
};
class PropAtRestCondition : public Condition {
  public:
    char pad[8];
    char value;
    char vfunc_6(void*, void*, void*);
};
struct Item {
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
    virtual char f11();
};
struct A {
    void* get();
};
struct B {
    void* get();
};
struct S {
    char ready();
    void* part();
};
extern "C" int __cdecl Check(void*, void*, void*, void*, void*);
extern char G1[];
extern char G2[];
char PropAtRestCondition::vfunc_6(void* a, void* c, void* d) {
    if (!Check(c, 0, G1, G2, 0))
        return 0;
    char result = 0;
    A* obj = (A*)c;
    void* p = obj->get();
    B* mot = (B*)p;
    p = mot->get();
    void* state = *(void**)((char*)p + 0x128);
    if (state && ((S*)state)->ready() && *(int*)((char*)((S*)state)->part() + 0x6c) == 1) {
        void* part = ((S*)state)->part();
        Item* item = *(Item**)((char*)part + 0x70);
        char v = value;
        result = item->f11() == v;
    }
    return result;
}
