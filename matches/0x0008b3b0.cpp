extern "C" void __stdcall init(const char*, int);
extern "C" unsigned char __cdecl get(const char*);
extern const char key[];
struct Init {
    Init(const char* s) { init(s, 1); }
};
class Method1 : public Init {
  public:
    virtual void f();
    char p0[12];
    unsigned char a;
    char p1[7];
    unsigned char b;
    char p2[3];
    const char* name;
    Method1(const char* s, const char* n) : Init(s) {
        name = n;
        b = get(key);
        a = get(key);
    }
};
class Closure1 : public Method1 {
  public:
    virtual void f();
    const char* val;
    Closure1(const char* s, const char* v, const char* n);
};
Closure1::Closure1(const char* s, const char* v, const char* n) : Method1(s, n) {
    val = v;
}
