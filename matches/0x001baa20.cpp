struct CtorV_001d0480 {
    CtorV_001d0480(void*, int);
    virtual void v_001d0480();
};
extern "C" unsigned char __cdecl query(const void*);
extern char key1, key2;
class Base : public CtorV_001d0480 {
  public:
    Base(void* name) : CtorV_001d0480(name, 1) { }
};
class Closure1_1baa20 : public Base {
  public:
    virtual void f();
    char pad[12];
    unsigned char a;
    char pad2[7];
    unsigned char b;
    char pad3[3];
    void* owner;
    Closure1_1baa20(void*, void*);
};
class Closure1 : public Closure1_1baa20 {
  public:
    virtual void f();
    void* fn;
    Closure1(void*, void*, void*);
};
Closure1_1baa20::Closure1_1baa20(void* name, void* obj) : Base(name) {
    owner = obj;
    b = query(&key1);
    a = query(&key2);
}
Closure1::Closure1(void* name, void* cb, void* obj) : Closure1_1baa20(name, obj) {
    fn = cb;
}