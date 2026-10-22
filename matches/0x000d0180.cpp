class Function_d0180 {
  public:
    Function_d0180(void*, int);
    virtual void run();
    char pad[12];
    unsigned char a;
    char pad2[7];
    unsigned char b;
    char pad3[3];
    void* p;
};
extern "C" unsigned char fn(void*);
extern void* g1;
extern void* g2;
class Method1 : public Function_d0180 {
  public:
    Method1(void* x, void* y) : Function_d0180(x, 1) {
        p = y;
        b = fn(&g1);
        a = fn(&g2);
    }
    virtual void run();
};
class Closure1 : public Method1 {
  public:
    Closure1(void*, void*, void*);
    virtual void run();
    void* q;
};
Closure1::Closure1(void* x, void* y, void* z) : Method1(x, z) {
    q = y;
}