class X_10c420 {
  public:
    char m[0xc];
    int value;
    char Set(int v);
};

char X_10c420::Set(int v) {
    value = v;
    return 1;
}
