extern "C" unsigned char parse(const char*);
extern char str1_aecd0[], str2[], str3[];
class Function_aecd0 {
  public:
    Function_aecd0(void*, int);
    virtual void f();
    char pad[12];
    unsigned char a, b;
    char pad2[6];
    unsigned char c;
    char pad3[3];
    int val;
    int other;
};
class Method2 : public Function_aecd0 {
  public:
    Method2(void* p, int n) : Function_aecd0(p, 2) {
        val = n;
        c = parse(str1_aecd0);
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