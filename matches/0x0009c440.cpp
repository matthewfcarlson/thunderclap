typedef unsigned char u8;
extern "C" void __stdcall FUN_001d0480(void*, int);
extern "C" u8 __cdecl FUN_001d04d0(const void*);
extern int gA_9c440, gB;
class Parent_9c440 {
  public:
    Parent_9c440(void* a) { FUN_001d0480(a, 2); }
};
class Method2 : public Parent_9c440 {
  public:
    virtual void Fn();
    char pad[0xc];
    u8 b10, b11;
    char pad2[6];
    u8 b18;
    char pad3[3];
    void* p1;
    void* p2;
    Method2(void* a, void* b) : Parent_9c440(a) {
        p1 = b;
        b18 = FUN_001d04d0(&gA_9c440);
        b10 = FUN_001d04d0(&gB);
        b11 = FUN_001d04d0(&gB);
    }
};
class Closure2 : public Method2 {
  public:
    virtual void Fn();
    Closure2(void*, void*, void*);
};
Closure2::Closure2(void* a, void* b, void* c) : Method2(a, c) {
    p2 = b;
}