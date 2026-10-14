class CSPManager;
class Base_1e0650 {
  public:
    virtual void basefn();
    Base_1e0650(const char*, int);
};
class Method3 : public Base_1e0650 {
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
Method3::Method3(const char* s, void* p) : Base_1e0650(s, 3) {
    x = p;
    d = fun(n1);
    a = fun(n2);
    b = fun(n2);
    c = fun(n3);
}