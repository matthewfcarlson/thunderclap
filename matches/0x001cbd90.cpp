typedef unsigned int uint;
extern "C" unsigned char parse(const char*);
extern const char* name1;
extern const char* name2;
class Base {
  public:
    Base(void*, int);
    virtual void f();
};
class Method1 : public Base {
  public:
    char pad[12];
    unsigned char a;
    char gap[7];
    unsigned char b;
    char gap2[3];
    void* m;
    Method1(void* p, void* v) : Base(p, 1) {
        m = v;
        b = parse((const char*)&name1);
        a = parse((const char*)&name2);
    }
    virtual void f();
};
class Closure1 : public Method1 {
  public:
    void* n;
    Closure1(void* p, void* q, void* v);
    virtual void f();
};
Closure1::Closure1(void* p, void* q, void* v) : Method1(p, v) {
    n = q;
}
