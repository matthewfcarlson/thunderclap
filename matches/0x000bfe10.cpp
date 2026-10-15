extern "C" unsigned char __cdecl Find(void*);
extern int gOne, gTwo;
class Parent {
  public:
    virtual void invoke();
    Parent(void*, int);
};
class Method1 : public Parent {
  public:
    virtual void invoke();
    char pad[12];
    unsigned char a;
    char pad2[7];
    unsigned char b;
    char pad3[3];
    void* ptr;
    Method1(void*, void*);
};
Method1::Method1(void* p, void* q) : Parent(p, 1) {
    ptr = q;
    b = Find(&gOne);
    a = Find(&gTwo);
}
class Closure1 : public Method1 {
  public:
    virtual void invoke();
    void* ptr2;
    Closure1(void*, void*, void*);
};
Closure1::Closure1(void* p, void* q, void* r) : Method1(p, r) {
    ptr2 = q;
}