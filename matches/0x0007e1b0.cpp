struct CtorV_001d0480 {
    CtorV_001d0480(void*, int);
    virtual void v_001d0480();
};
extern "C" unsigned char Decode(const void*);
extern int key1, key2;
class Function_7e1b0 : public CtorV_001d0480 {
  public:
    Function_7e1b0(void* p) : CtorV_001d0480(p, 1) { }
};
class Method1 : public Function_7e1b0 {
  public:
    virtual void Invoke(int);
    char padding[0xc];
    unsigned char a;
    char padding2[7];
    unsigned char b;
    char padding3[3];
    int arg;
    Method1(void* p, int x) : Function_7e1b0(p) {
        arg = x;
        b = Decode(&key1);
        a = Decode(&key2);
    }
};
class Closure1 : public Method1 {
  public:
    virtual void Invoke(int);
    int data;
    Closure1(void*, int, int);
};
Closure1::Closure1(void* p, int x, int y) : Method1(p, y) {
    data = x;
}