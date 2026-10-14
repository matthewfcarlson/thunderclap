class X_77e10 {
  public:
    char pad[0x14];
    int m;
    char Set(int v);
};

char X_77e10::Set(int v) {
    m = v;
    return 1;
}
