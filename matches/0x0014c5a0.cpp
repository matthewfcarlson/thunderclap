class Obj_14c5a0 {
  public:
    char pad[0xc];
    unsigned char mVal;
    unsigned char Set(unsigned char v);
};
unsigned char Obj_14c5a0::Set(unsigned char v) {
    mVal = v;
    return 1;
}