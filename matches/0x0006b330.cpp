class X_6b330 {
  public:
    char Pad[0x1c];
    int mValue;
    char Set(int v);
};

char X_6b330::Set(int v) {
    mValue = v;
    return 1;
}
