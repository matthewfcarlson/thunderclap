class DefaultFrameControllerHandler {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual char vfunc_3(unsigned int);
    virtual void f4();
};
char DefaultFrameControllerHandler::vfunc_3(unsigned int x) {
    switch (x) {
    case 0x4e525450U:
    case 0x584554U:
    case 0x475142U:
    case 0x4d4143U:
    case 0x505845U:
    case 0x584645U:
    case 0x44414853U:
    case 0x4554494cU:
    case 0x53595350U:
    case 0x4e525453U:
    case 0x53495650U:
    case 0x53495653U:
    case 0x54525650U:
    case 0x58545256U:
        return 1;
    default:
        return 0;
    }
}