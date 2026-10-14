class C_47b50 {
  public:
    char pad[0x18];
    int mValue;
    char Set(int v);
};

char C_47b50::Set(int v) {
    mValue = v;
    return 1;
}
