class Obj {
  public:
    char Set(int x);
    char mPad[0x10];
    int m10;
};

char Obj::Set(int x) {
    m10 = x;
    return 1;
}
