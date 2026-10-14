class A {
  public:
    char m[0x10];
    int mVal;
    char Set(int v);
};

char A::Set(int v) {
    mVal = v;
    return 1;
}
