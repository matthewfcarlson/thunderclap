class X {
  public:
    char pad[0x1a];
    char mValue;
    char Set(char v);
};

char X::Set(char v) {
    mValue = v;
    return 1;
}
