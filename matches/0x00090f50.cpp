struct CtorV_001d0480 {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
extern "C" unsigned char lookup(const char*);
extern char key1[];
extern char key2[];
class Function_90f50 : public CtorV_001d0480 {
  public:
    char pad[4];
    Function_90f50(const char* p) : CtorV_001d0480(p, 1) { }
};
class Method1 : public Function_90f50 {
  public:
    virtual void fn();
    char pad[8];
    unsigned char flag1;
    char pad2[7];
    unsigned char flag2;
    char pad3[3];
    void* arg2;
    void* arg3;
    Method1(const char* p, void* a) : Function_90f50(p) {
        arg2 = a;
        flag2 = lookup(key1);
        flag1 = lookup(key2);
    }
};
class Closure1 : public Method1 {
  public:
    virtual void fn();
    Closure1(const char* p, void* a, void* b);
};
Closure1::Closure1(const char* p, void* a, void* b) : Method1(p, b) {
    arg3 = a;
}