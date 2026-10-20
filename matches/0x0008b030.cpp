extern "C" unsigned char __cdecl getFlag(const char*);
extern const char key1[];
extern const char key2[];
class CGameFlowManager;
class Base {
  public:
    virtual void f();
    Base(CGameFlowManager*, int);
    char pad[0xc];
    unsigned char b;
    char pad2[7];
    unsigned char a;
    char pad3[3];
    int val;
};
class Closure1_8b030 : public Base {
  public:
    virtual void f();
    Closure1_8b030(CGameFlowManager*, int);
};
class Closure1 : public Closure1_8b030 {
  public:
    virtual void f();
    int extra;
    Closure1(CGameFlowManager*, int, int);
};
Closure1_8b030::Closure1_8b030(CGameFlowManager* p, int x) : Base(p, 1) {
    val = x;
    a = getFlag(key1);
    b = getFlag(key2);
}
Closure1::Closure1(CGameFlowManager* p, int x, int y) : Closure1_8b030(p, y) {
    extra = x;
}