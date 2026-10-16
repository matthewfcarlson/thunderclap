class Function {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
class Function4 : public Function {
  public:
    virtual void vfunc_0();
    virtual void vfunc_2(int, int*, int);
    char pad[24];
    void(__cdecl* fn)(int, const char*, const char*, float);
};
void Function4::vfunc_2(int, int* a, int) {
    int* p = a;
    int x = *p++;
    const char* y = (const char*)*p++;
    const char* z = (const char*)*p++;
    float w = *(float*)p;
    fn(x, y, z, w);
}