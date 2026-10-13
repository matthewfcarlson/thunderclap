class Obj {
  public:
    char pad[0x10];
    unsigned char mVal;
    unsigned char Fn(unsigned char arg);
};

unsigned char Obj::Fn(unsigned char arg) {
    mVal = arg;
    return 1;
}
