extern "C" unsigned char __cdecl Lookup(const char*);
extern const char keyA[];
extern const char keyB[];
class Base {
  public:
    virtual void Invoke(const char*);
    Base(const char*, int);
    char pad[12];
    unsigned char flagB;
    char pad2[7];
    unsigned char flagA;
    char pad3[3];
    void* member;
};
class Method1 : public Base {
  public:
    virtual void Invoke(const char*);
    Method1(const char* s, void* p) : Base(s, 1) {
        member = p;
        flagA = Lookup(keyA);
        flagB = Lookup(keyB);
    }
};
class Closure1 : public Method1 {
  public:
    virtual void Invoke(const char*);
    void* extra;
    Closure1(const char*, void*, void*);
};
Closure1::Closure1(const char* s, void* x, void* p) : Method1(s, p) {
    extra = x;
}