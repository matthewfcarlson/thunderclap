extern "C" char fn(char*);
extern char g1[];
extern char g2[];
class Pre {
  public:
    Pre(void*, int);
    virtual void v();
};
class Method1 : public Pre {
  public:
    char pad0[12];
    char a;
    char pad1[7];
    char b;
    char pad2[3];
    int value;
    Method1(void* p, int x) : Pre(p, 1) {
        value = x;
        b = fn(g1);
        a = fn(g2);
    }
    virtual void v();
};
class Closure1 : public Method1 {
  public:
    int value2;
    Closure1(void* p, int n, int x);
    virtual void v();
};
Closure1::Closure1(void* p, int n, int x) : Method1(p, x) {
    value2 = n;
}
