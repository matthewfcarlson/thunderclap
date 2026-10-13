class Obj {
  public:
    char Fn(int a);
    char mPad[0x0c];
    int mVal;
};
char Obj::Fn(int a) {
    mVal = a;
    return 1;
}
