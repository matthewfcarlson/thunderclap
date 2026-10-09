class Function {
  public:
    virtual void f0();
    virtual void f1();
};
class Method0 : public Function {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2(void*, void*, unsigned*);
    char pad[24];
};
void Method0::f2(void* a, void* b, unsigned* out) {
    unsigned(__fastcall * p)(void*) = *(unsigned(__fastcall**)(void*))((char*)this + 0x1c);
    unsigned v = p(a);
    if (out)
        *out = v;
}
