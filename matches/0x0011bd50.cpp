class Obj_11bd50 {
  public:
    char pad[0x14];
    unsigned int mVal;
    unsigned char Set(unsigned int v);
};
unsigned char Obj_11bd50::Set(unsigned int v) {
    mVal = v;
    return 1;
}
