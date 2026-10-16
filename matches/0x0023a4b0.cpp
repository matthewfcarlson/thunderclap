namespace fight {
class IFileStringReader {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual int vfunc_4();
    virtual int vfunc_5();
    virtual void vfunc_6();
    char pad[8];
    char a;
    char b;
};
int IFileStringReader::vfunc_5() {
    int r = vfunc_4();
    a = 0;
    b = 0;
    return r;
}
} // namespace fight