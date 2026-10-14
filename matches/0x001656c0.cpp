class Obj {
  public:
    char m0, m1, m2, m3, m4, m5, m6, m7, m8, m9, mA, mB;
    int mC;
    char Set(int x);
};
char Obj::Set(int x) {
    mC = x;
    return 1;
}
