class X_16ede0 {
  public:
    char Pad0[12];
    int mValue;
    char Set(int v);
};

char X_16ede0::Set(int v) {
    mValue = v;
    return 1;
}
