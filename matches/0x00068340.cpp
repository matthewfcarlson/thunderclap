class Obj {
  public:
    char Set(int v);
    char mPad[12];
    int mVal;
};
char Obj::Set(int v) {
    mVal = v;
    return 1;
}
