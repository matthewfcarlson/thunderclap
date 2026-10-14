class X_133800 {
  public:
    char pad[0x10];
    int mValue;
    char Set(int v);
};

char X_133800::Set(int v) {
    mValue = v;
    return 1;
}
