class BinReader {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual unsigned char vfunc_3();
    char pad[0xC];
};
unsigned char BinReader::vfunc_3() {
    return *(unsigned char*)((char*)this + 0xC);
}