class Obj {
  public:
    char pad[0x14];
    unsigned int mVal;
    unsigned char Set(unsigned int v);
};
unsigned char Obj::Set(unsigned int v) {
    mVal = v;
    return 1;
}
