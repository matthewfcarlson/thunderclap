namespace fight {
class StreamStringReader {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual int f4();
    virtual int vfunc_5();
    virtual void f6();
    char pad[12];
    char a;
    char b;
};
int StreamStringReader::vfunc_5() {
    int result = f4();
    a = 0;
    b = 0;
    return result;
}
} // namespace fight