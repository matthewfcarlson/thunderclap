class Vector1DOFChannel {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void vfunc_3(int, float*, unsigned int*);
    virtual void f4();
    virtual void f5();
    char pad0[0x10];
    short* indices;
    int component;
    unsigned int a, b, c;
    unsigned int* values;
};
void Vector1DOFChannel::vfunc_3(int index, float* out, unsigned int* vec) {
    *out = (float)(int)indices[index];
    vec[0] = a;
    vec[1] = b;
    vec[2] = c;
    vec[component] = values[index];
}