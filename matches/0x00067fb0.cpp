class Obj_67fb0 {
  public:
    char Set(int v);
    char mPad[0x48];
    int mVal;
};

char Obj_67fb0::Set(int v) {
    mVal = v;
    return 1;
}
