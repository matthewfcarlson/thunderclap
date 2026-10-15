extern char __cdecl ReadFlag(const char*);
extern char flagA[];
extern char flagB[];
class Base {
  public:
    Base(void*, int);
    virtual void Run();
    char pad[12];
};
class Method1 : public Base {
  public:
    Method1(void* a, void* c) : Base(a, 1) {
        p = c;
        y = ReadFlag(flagA);
        x = ReadFlag(flagB);
    }
    virtual void Run();
    char x;
    char pad2[7];
    char y;
    char pad3[3];
    void* p;
};
class Closure1 : public Method1 {
  public:
    Closure1(void* a, void* b, void* c);
    virtual void Run();
    void* q;
};
Closure1::Closure1(void* a, void* b, void* c) : Method1(a, c) {
    q = b;
}
