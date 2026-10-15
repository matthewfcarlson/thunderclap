class Base {
  public:
    virtual void invoke();
    Base(const char*, int);
};
extern unsigned char __cdecl FUN_001d04d0(const char*);
extern const char a[], b[];
class Method1 : public Base {
  public:
    virtual void invoke();
    char pad[12];
    unsigned char v1;
    char pad2[7];
    unsigned char v2;
    char pad3[3];
    void* object;
    Method1(const char*, void*, void*);
};
class Closure1 : public Method1 {
  public:
    virtual void invoke();
    void* other;
    Closure1(const char*, void*, void*);
};
Closure1::Closure1(const char* s, void* obj, void* p) : Method1(s, obj, p) {
    other = obj;
}
Method1::Method1(const char* s, void* obj, void* p) : Base(s, 1) {
    object = p;
    v2 = FUN_001d04d0(a);
    v1 = FUN_001d04d0(b);
}
