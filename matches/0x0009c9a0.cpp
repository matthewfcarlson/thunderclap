struct CtorV_001d0480 {
    CtorV_001d0480(void*, int);
    virtual void v_001d0480();
};
extern "C" unsigned char Check(const void*);
extern char gA[];
extern char gB[];
class Function_9c9a0 : public CtorV_001d0480 {
  public:
    Function_9c9a0(void* p) : CtorV_001d0480(p, 1) { }
};
class Method1 : public Function_9c9a0 {
  public:
    virtual void invoke(float);
    char pad[12];
    unsigned char a;
    char pad2[7];
    unsigned char b;
    char pad3[3];
    int x;
    Method1(void* p, int v) : Function_9c9a0(p) {
        x = v;
        b = Check(gB);
        a = Check(gA);
    }
};
class Closure1 : public Method1 {
  public:
    virtual void invoke(float);
    int y;
    Closure1(void* p, int w, int v);
};
Closure1::Closure1(void* p, int w, int v) : Method1(p, v) {
    y = w;
}
