class Function_7d050 {
  public:
    Function_7d050(const char*, int);
    virtual void f();
};
extern "C" unsigned char __cdecl check(const char*);
extern const char a_7d050[], b[], c[], d[];
class Method3 : public Function_7d050 {
  public:
    Method3(const char*, int);
    virtual void f();
    char pad[12];
    unsigned char x, y, z;
    char pad2[5];
    unsigned char w;
    char pad3[3];
    int n;
};
Method3::Method3(const char* s, int k) : Function_7d050(s, 3) {
    n = k;
    w = check(a_7d050);
    x = check(b);
    y = check(c);
    z = check(d);
}