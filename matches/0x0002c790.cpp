extern void __stdcall FUN_001d0480(const char*, int);
extern unsigned char __cdecl FUN_001d04d0(const char*);
extern const char name1[];
extern const char name2[];
class Base {
  public:
    Base(const char* s) { FUN_001d0480(s, 1); }
};
class Method1 : public Base {
  public:
    virtual void fn();
    char pad[12];
    unsigned char a;
    char pad2[7];
    unsigned char b;
    char pad3[3];
    int c;
    Method1(const char*, int);
};
Method1::Method1(const char* s, int v) : Base(s) {
    c = v;
    b = FUN_001d04d0(name1);
    a = FUN_001d04d0(name2);
}
