class SimpleChunkHandler {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual char vfunc_6(unsigned int);
    virtual void f7();
};
class OldFrameControllerLoader : public SimpleChunkHandler {
  public:
    virtual char vfunc_6(unsigned int);
};
char OldFrameControllerLoader::vfunc_6(unsigned int x) {
    switch (x) {
    case 0x4554494c:
    case 0x584554:
    case 0x475142:
    case 0x4d4143:
    case 0x505845:
    case 0x584645:
    case 0x44414853:
    case 0x53495653:
    case 0x4e525450:
    case 0x4e525453:
    case 0x53495650:
    case 0x54525650:
    case 0x58545256:
        return 1;
    default:
        return 0;
    }
}