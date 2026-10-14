class Obj_16e9e0 {
  public:
    char pad[0x14];
    int mVal;
    unsigned char Set(int v);
};
unsigned char Obj_16e9e0::Set(int v) {
    mVal = v;
    return 1;
}
