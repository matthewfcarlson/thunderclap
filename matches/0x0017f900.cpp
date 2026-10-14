class X {
  public:
    char pad[0xc];
    int mValue;
    char Set(int v);
};

char X::Set(int v) {
    mValue = v;
    return 1;
}
