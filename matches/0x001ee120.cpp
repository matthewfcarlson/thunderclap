class Function_1ee120 {
  public:
    virtual void F0();
    Function_1ee120(int, int);
};
extern "C" unsigned char Check(const char*);
extern char a[], b[];
class Method1 : public Function_1ee120 {
  public:
    virtual void F();
    char pad[12];
    unsigned char x;
    char pad2[7];
    unsigned char y;
    char pad3[3];
    void* p;
    Method1(int v, void* q) : Function_1ee120(v, 1), p(q) {
        y = Check(a);
        x = Check(b);
    }
};
class Closure1 : public Method1 {
  public:
    virtual void G();
    void* r;
    Closure1(int v, void* r0, void* q);
};
Closure1::Closure1(int v, void* r0, void* q) : Method1(v, q), r(r0) {}