extern char gKey[];
extern "C" unsigned char __cdecl lookup(const char*);
class Function_1e2610 {
  public:
    Function_1e2610(const char*, int) throw();
    virtual void action();
};
class Method1_1e2610 : public Function_1e2610 {
  public:
    unsigned char pad[12];
    unsigned char flag1;
    char p1[7];
    unsigned char flag2;
    char p2[3];
    const char* third;
    Method1_1e2610(const char* a, const char* c) throw() : Function_1e2610(a, 1) {
        third = c;
        flag2 = lookup(gKey);
        flag1 = lookup(gKey);
    }
    virtual void action();
};
class Closure1_1e2610 : public Method1_1e2610 {
  public:
    const char* second;
    Closure1_1e2610(const char* a, const char* b, const char* c) throw();
    virtual void action();
};
Closure1_1e2610::Closure1_1e2610(const char* a, const char* b, const char* c) throw() : Method1_1e2610(a, c) {
    second = b;
}