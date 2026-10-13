class Obj {
  public:
    char Set(int v);
    char mPad[0x48];
    int mVal;
};

char Obj::Set(int v) {
    mVal = v;
    return 1;
}
