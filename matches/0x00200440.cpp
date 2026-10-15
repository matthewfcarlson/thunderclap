extern char gName[];
extern unsigned char __cdecl GetFlag(const char*);
class Base {
  public:
    Base(const char*, int);
    virtual void Fn();
    char pad[0xc];
};
class Method1 : public Base {
  public:
    Method1(const char* s, const char* t) : Base(s, 1) {
        m = t;
        a = GetFlag(gName);
        b = GetFlag(gName);
    }
    virtual void Fn();
    char b;
    char pad2[7];
    char a;
    char pad3[3];
    const char* m;
};
class Closure1 : public Method1 {
  public:
    Closure1(const char* s, const char* t, const char* u);
    virtual void Fn();
    const char* n;
};
Closure1::Closure1(const char* s, const char* t, const char* u) : Method1(s, u) {
    n = t;
}
