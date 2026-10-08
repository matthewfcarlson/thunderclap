namespace pure3d {
struct S { char pad[0xc]; void* value; };
class pddiBaseContext {
public:
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void vfunc_10(void* value);
    char pad[0x44];
    S* p;
};
void pddiBaseContext::vfunc_10(void* value) { p->value = value; }
}