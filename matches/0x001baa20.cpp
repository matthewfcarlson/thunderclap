extern "C" void __stdcall init(void*, int);
extern "C" unsigned char __cdecl query(const void*);
extern char key1, key2;
class Base {
  public:
    Base(void* name) { init(name, 1); }
};
class Method1 : public Base {
  public:
    virtual void f();
    char pad[12];
    unsigned char a;
    char pad2[7];
    unsigned char b;
    char pad3[3];
    void* owner;
    Method1(void*, void*);
};
class Closure1 : public Method1 {
  public:
    virtual void f();
    void* fn;
    Closure1(void*, void*, void*);
};
Method1::Method1(void* name, void* obj) : Base(name) {
    owner = obj;
    b = query(&key1);
    a = query(&key2);
}
Closure1::Closure1(void* name, void* cb, void* obj) : Method1(name, obj) {
    fn = cb;
}