class X_14c660 {
  public:
    char Pad[0x10];
    int mVal;
    char Set(int v);
};

char X_14c660::Set(int v) {
    mVal = v;
    return 1;
}
