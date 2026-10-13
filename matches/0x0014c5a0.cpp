class Obj {
  public:
    char pad[0xc];
    unsigned char mVal;
    unsigned char Set(unsigned char v);
};
unsigned char Obj::Set(unsigned char v) {
    mVal = v;
    return 1;
}