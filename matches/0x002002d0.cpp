extern char gA[];
extern char gB[];
char __cdecl Lookup(const char*);
class Function_2002d0 {
  public:
    Function_2002d0(const char*, int);
    virtual void f0();
};
class Method1_2002d0 : public Function_2002d0 {
  public:
    char pad4[12];
    char v10;
    char pad11[7];
    char v18;
    char pad19[3];
    const char* v1c;
    Method1_2002d0(const char* a, const char* b) : Function_2002d0(a, 1) {
        v1c = b;
        v18 = Lookup(gA);
        v10 = Lookup(gB);
    }
    virtual void f1();
};
class Closure1_2002d0 : public Method1_2002d0 {
  public:
    int v20;
    Closure1_2002d0(const char* a, int b, const char* c);
    virtual void f2();
};
Closure1_2002d0::Closure1_2002d0(const char* a, int b, const char* c) : Method1_2002d0(a, c), v20(b) {}