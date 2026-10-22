typedef unsigned int uint;
extern "C" unsigned char __cdecl lookup(const char*);
extern char firstName[];
extern char secondName[];
class Function_1bfe10 {
  public:
    Function_1bfe10(void*, int);
    virtual void v0();
    char pad[12];
    unsigned char a;
    char pad2[7];
    unsigned char b;
    char pad3[3];
    void* p;
};
class Method1 : public Function_1bfe10 {
  public:
    Method1(void* x, void* z) : Function_1bfe10(x, 1) {
        p = z;
        b = lookup(firstName);
        a = lookup(secondName);
    }
    virtual void v0();
};
class Closure1 : public Method1 {
  public:
    void* q;
    Closure1(void*, void*, void*);
    virtual void v0();
};
Closure1::Closure1(void* x, void* y, void* z) : Method1(x, z) {
    q = y;
}