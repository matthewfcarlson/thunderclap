class Obj {
  public:
    char Fn(int x);
    char mPad[0xec];
    int mField;
};
char Obj::Fn(int x) {
    mField = x;
    return 1;
}
