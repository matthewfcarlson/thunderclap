class X {
  public:
    char Pad[0x1c];
    int mValue;
    char Set(int v);
};

char X::Set(int v) {
    mValue = v;
    return 1;
}
