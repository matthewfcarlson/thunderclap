struct Item {
    int x;
};
extern Item g1, g2;
extern "C" unsigned char check(Item*);
class Base {
  public:
    Base(const char*, int);
    virtual void invoke();
    char pad[12];
    unsigned char f10;
    char pad2[7];
    unsigned char f18;
    char pad3[3];
    void* target;
};
class Method : public Base {
  public:
    Method(const char*, void*);
    virtual void invoke();
};
inline Method::Method(const char* name, void* a) : Base(name, 1) {
    target = a;
    f18 = check(&g1);
    f10 = check(&g2);
}
class Closure : public Method {
  public:
    Closure(const char*, void*, void*);
    virtual void invoke();
    void* arg;
};
Closure::Closure(const char* name, void* p, void* a) : Method(name, a) {
    arg = p;
}