class Function {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
class Function2 : public Function {
  public:
    virtual void vfunc_2(int, unsigned int*, int);
    char pad[24];
    void(__cdecl* mFn)(float, float);
};
void Function2::vfunc_2(int x, unsigned int* p, int y) {
    mFn(*(float*)p, *((float*)p + 1));
}