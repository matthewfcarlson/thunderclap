class X {
  public:
    char Pad0[12];
    int mValue;
    char Set(int v);
};

char X::Set(int v) {
    mValue = v;
    return 1;
}
