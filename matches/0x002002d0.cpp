extern char gA[];
extern char gB[];
char __cdecl Lookup(const char*);
class Root {
  public:
    Root(const char*, int);
    virtual void f0();
};
class Method : public Root {
  public:
    char pad4[12];
    char v10;
    char pad11[7];
    char v18;
    char pad19[3];
    const char* v1c;
    Method(const char* a, const char* b) : Root(a, 1) {
        v1c = b;
        v18 = Lookup(gA);
        v10 = Lookup(gB);
    }
    virtual void f1();
};
class Closure : public Method {
  public:
    int v20;
    Closure(const char* a, int b, const char* c);
    virtual void f2();
};
Closure::Closure(const char* a, int b, const char* c) : Method(a, c), v20(b) {}