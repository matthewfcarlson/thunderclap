class X {
  public:
    char Set(int v);
    char pad[0x10];
    int mValue;
};

char X::Set(int v) {
    mValue = v;
    return 1;
}
