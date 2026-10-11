class C10 {
  public:
    void F();
};
class C14 {
  public:
    void F(int);
};
class C18 {
  public:
    void F(int);
};
class C1c;
class C20;
class C24 {
  public:
    void F(C1c*);
};
class C28 {
  public:
    void F();
};
class C2c {
  public:
    void F(int);
};
class C30 {
  public:
    void F(int, int);
};
class C48 {
  public:
    void F();
};
class A;
class C20 {
  public:
    void F(A*, int*, int, C30*, C24*);
};
struct State {
    int id;
};
class A {
  public:
    char pad0[4];
    State* p4;
    char pad8[8];
    C10* p10;
    C14* p14;
    C18* p18;
    C1c* p1c;
    C20* p20;
    C24* p24;
    C28* p28;
    C2c* p2c;
    C30* p30;
    char pad34[20];
    C48* p48;
    void Run(int);
};
extern bool __cdecl Check();
void A::Run(int arg) {
    p10->F();
    p14->F(arg);
    if (Check())
        return;
    if (p4->id != 7) {
        p30->F(arg, 0);
        p48->F();
        p20->F(this, (int*)p4, arg, p30, p24);
        p2c->F(arg);
        p28->F();
        p24->F(p1c);
        return;
    }
    p18->F(arg);
}
