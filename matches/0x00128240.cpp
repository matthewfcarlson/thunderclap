extern "C" int Check(void*, int, int, int, int);
class CF {
  public:
    virtual bool vfunc_0(void* a);
};
bool CF::vfunc_0(void* a) {
    return Check(a, 0, 0x491ca8, 0x4a8a50, 0) != 0;
}
