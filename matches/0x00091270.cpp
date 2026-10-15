extern "C" void __stdcall init(const char*, int);
extern "C" unsigned char read(const char*);
extern const char a[];
extern const char b[];
class Storage {
  public:
    Storage(const char* s) { init(s, 1); }
    char pad[0xc];
    unsigned char f10;
    char pad2[7];
    unsigned char f18;
    char pad3[3];
    int f1c;
};
class Method1 : public Storage {
  public:
    virtual void invoke();
    Method1(const char* s, int n) : Storage(s) {
        f1c = n;
        f18 = read(a);
        f10 = read(b);
    }
};
class Closure1 : public Method1 {
  public:
    virtual void invoke();
    int f20;
    Closure1(const char* s, int n, int m);
};
Closure1::Closure1(const char* s, int n, int m) : Method1(s, m), f20(n) {}