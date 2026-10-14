class Obj {
  public:
    char mPad[0xc];
    int mField;
    char Set(int x);
};

char Obj::Set(int x) {
    mField = x;
    return 1;
}
