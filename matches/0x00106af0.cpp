struct CtorV_001d0480 {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
extern "C" unsigned char __cdecl look(const char*);
extern const char s1_106af0[], s2[], s3[], s4[];
class Base_106af0 : public CtorV_001d0480 {
  public:
    Base_106af0(const char* name) : CtorV_001d0480(name, 3) { }
};
class Method3 : public Base_106af0 {
  public:
    virtual void f();
    char pad[12];
    unsigned char a, b, c;
    char pad2[5];
    unsigned char d;
    char pad3[3];
    int value;
    Method3(const char*, int);
};
Method3::Method3(const char* name, int v) : Base_106af0(name) {
    value = v;
    d = look(s1_106af0);
    a = look(s2);
    b = look(s3);
    c = look(s4);
}