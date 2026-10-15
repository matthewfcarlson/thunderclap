extern char gKey[];
extern "C" unsigned char __cdecl lookup(const char*);
class Root {
  public:
    Root(const char*, int) throw();
    virtual void action();
};
class Method : public Root {
  public:
    unsigned char pad[12];
    unsigned char flag1;
    char p1[7];
    unsigned char flag2;
    char p2[3];
    const char* third;
    Method(const char* a, const char* c) throw() : Root(a, 1) {
        third = c;
        flag2 = lookup(gKey);
        flag1 = lookup(gKey);
    }
    virtual void action();
};
class Closure : public Method {
  public:
    const char* second;
    Closure(const char* a, const char* b, const char* c) throw();
    virtual void action();
};
Closure::Closure(const char* a, const char* b, const char* c) throw() : Method(a, c) {
    second = b;
}