class X_12b290 {
  public:
    char pad[0x10];
    int m;
    char Set(int v);
};

char X_12b290::Set(int v) {
    m = v;
    return 1;
}
