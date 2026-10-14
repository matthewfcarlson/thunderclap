class CSPManager;
class Base {
  public:
    virtual void basefn();
    Base(const char*, int);
};
class Method3 : public Base {
  public:
    virtual void dummy();
    Method3(const char*, void*);
    char pad[0x0c];
    char a, b, c;
    char pad2[5];
    char d;
    char pad3[3];
    void* x;
};
extern const char n1[], n2[], n3[];
extern char fun(const char*);
Method3::Method3(const char* s, void* p) : Base(s, 3) {
    x = p;
    d = fun(n1);
    a = fun(n2);
    b = fun(n2);
    c = fun(n3);
}