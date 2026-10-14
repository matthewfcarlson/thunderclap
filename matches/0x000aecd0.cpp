extern "C" unsigned char parse(const char*);
extern char str1[], str2[], str3[];
class Root {
  public:
    Root(void*, int);
    virtual void f();
    char pad[12];
    unsigned char a, b;
    char pad2[6];
    unsigned char c;
    char pad3[3];
    int val;
    int other;
};
class Method2 : public Root {
  public:
    Method2(void* p, int n) : Root(p, 2) {
        val = n;
        c = parse(str1);
        a = parse(str2);
        b = parse(str3);
    }
    virtual void f();
};
class Closure2 : public Method2 {
  public:
    Closure2(void* p, int m, int n);
    virtual void f();
};
Closure2::Closure2(void* p, int m, int n) : Method2(p, n) {
    other = m;
}