// Same code shape as 0x0002e080 (propagated; names are from that function)
class Function {
  public:
    virtual void f0();
    virtual void f1();
};
class Method0Base_1f79e0 : public Function {
  public:
    char pad[0x18];
    float(__fastcall* fn)(void*);
    virtual void f2(void* a, void* b, float* out);
};
void Method0Base_1f79e0::f2(void* a, void* b, float* out) {
    float(__fastcall * f)(void*) = fn;
    float value = f(a);
    if (out)
        *out = value;
}
