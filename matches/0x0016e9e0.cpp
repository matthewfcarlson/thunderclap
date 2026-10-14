class Obj {
  public:
    char pad[0x14];
    int mVal;
    unsigned char Set(int v);
};
unsigned char Obj::Set(int v) {
    mVal = v;
    return 1;
}
