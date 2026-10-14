// cl-flags: /O2
class X_1330a0 {
  public:
    char pad[0x20];
    int mVal;
    char Set(int p);
};

char X_1330a0::Set(int p) {
    mVal = p;
    return 1;
}
