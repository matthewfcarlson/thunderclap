namespace pure3d {
class pddiBaseContext {
public:
    virtual void f0(); virtual void f1(); virtual void f2();
    virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8();
    virtual float vfunc_9();
    virtual void f10();
    char pad[0x44];
    void* member;
};
float pddiBaseContext::vfunc_9() { return *(float*)((char*)member + 8); }
}