class Obj_115020 {
  public:
    char pad[0x10];
    unsigned char mVal;
    unsigned char Fn(unsigned char arg);
};

unsigned char Obj_115020::Fn(unsigned char arg) {
    mVal = arg;
    return 1;
}
