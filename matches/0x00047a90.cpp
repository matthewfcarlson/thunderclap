class X_47a90 {
  public:
    char pad[12];
    int mVal;
    char Set(int v);
};

char X_47a90::Set(int v) {
    mVal = v;
    return 1;
}
