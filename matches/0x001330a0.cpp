// cl-flags: /O2
class X {
  public:
    char pad[0x20];
    int mVal;
    char Set(int p);
};

char X::Set(int p) {
    mVal = p;
    return 1;
}
