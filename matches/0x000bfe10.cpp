extern "C" unsigned char __cdecl Find(void*);
extern int gOne, gTwo;
class Parent {
  public:
    virtual void invoke();
    Parent(void*, int);
};
class Closure1_bfe10 : public Parent {
  public:
    virtual void invoke();
    char pad[12];
    unsigned char a;
    char pad2[7];
    unsigned char b;
    char pad3[3];
    void* ptr;
    Closure1_bfe10(void*, void*);
};
Closure1_bfe10::Closure1_bfe10(void* p, void* q) : Parent(p, 1) {
    ptr = q;
    b = Find(&gOne);
    a = Find(&gTwo);
}
class Closure1 : public Closure1_bfe10 {
  public:
    virtual void invoke();
    void* ptr2;
    Closure1(void*, void*, void*);
};
Closure1::Closure1(void* p, void* q, void* r) : Closure1_bfe10(p, r) {
    ptr2 = q;
}