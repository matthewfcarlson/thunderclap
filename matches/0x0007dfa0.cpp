extern "C" unsigned char __cdecl FUN_001d04d0(const char*);
extern const char a[], b[], c[];
class Base_7dfa0 {
  public:
    Base_7dfa0(const char*, int);
    virtual void f();
};
class Method_7dfa0 : public Base_7dfa0 {
  public:
    Method_7dfa0(const char*, int);
    virtual void f();
    char pad[0xc];
    unsigned char x, y;
    char pad2[6];
    unsigned char z;
    char pad3[3];
    int arg;
};
class Closure_7dfa0 : public Method_7dfa0 {
  public:
    virtual void f();
    int extra;
    Closure_7dfa0(const char*, int, int);
};
inline Method_7dfa0::Method_7dfa0(const char* s, int v) : Base_7dfa0(s, 2) {
    arg = v;
    z = FUN_001d04d0(a);
    x = FUN_001d04d0(b);
    y = FUN_001d04d0(c);
}
Closure_7dfa0::Closure_7dfa0(const char* s, int v, int w) : Method_7dfa0(s, w) {
    extra = v;
}