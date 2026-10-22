extern "C" char __cdecl getFlag(const char*);
extern const char flagA[];
extern const char flagB[];
class Function_1cbe20 {
  public:
    Function_1cbe20(void*, int);
    virtual void f0();
    char pad[12];
    char a;
    char pad2[7];
    char b;
    char pad3[3];
    void* handler;
};
class Method1_1cbe20 : public Function_1cbe20 {
  public:
    virtual void f1();
    Method1_1cbe20(void* p, void* h) : Function_1cbe20(p, 1) {
        handler = h;
        b = getFlag(flagA);
        a = getFlag(flagB);
    }
};
class Closure1_1cbe20 : public Method1_1cbe20 {
  public:
    virtual void f2();
    void* extra;
    Closure1_1cbe20(void* p, void* q, void* h);
};
Closure1_1cbe20::Closure1_1cbe20(void* p, void* q, void* h) : Method1_1cbe20(p, h) {
    extra = q;
}