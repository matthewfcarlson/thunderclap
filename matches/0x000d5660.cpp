struct CtorV_001d0480 {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
extern "C" unsigned char __cdecl check(const char*);
extern const char s1_d5660[], s2[], s3[], s4[];
class Base_d5660 : public CtorV_001d0480 {
  public:
    Base_d5660(const char* str) : CtorV_001d0480(str, 3) { }
};
class Method_d5660 : public Base_d5660 {
  public:
    virtual void f();
    char pad[12];
    char a, b, c;
    char pad2[5];
    char d;
    char pad3[3];
    int value;
    Method_d5660(const char*, int);
};
Method_d5660::Method_d5660(const char* str, int n) : Base_d5660(str) {
    value = n;
    d = check(s1_d5660);
    a = check(s2);
    b = check(s3);
    c = check(s4);
}