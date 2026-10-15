class CWorldCollisionManager;
extern void __stdcall FUN_001d0480(const char*, int);
extern unsigned char __cdecl FUN_001d04d0(const void*);
extern int g1, g2;
class Base {
  public:
    Base(const char* s) { FUN_001d0480(s, 1); }
};
class Method1 : public Base {
  public:
    virtual void Invoke();
    char pad[0xc];
    unsigned char b10;
    char pad2[7];
    unsigned char b18;
    char pad3[3];
    CWorldCollisionManager* obj;
    Method1(const char* s, CWorldCollisionManager* o) : Base(s) {
        obj = o;
        b18 = FUN_001d04d0(&g1);
        b10 = FUN_001d04d0(&g2);
    }
};
class Closure1 : public Method1 {
  public:
    virtual void Invoke();
    int data;
    Closure1(const char*, int, CWorldCollisionManager*);
};
Closure1::Closure1(const char* s, int d, CWorldCollisionManager* o) : Method1(s, o) {
    data = d;
}