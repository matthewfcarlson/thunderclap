class C_139c40 {
  public:
    char pad[0x34];
    int mValue;
    char Set(int v);
};

char C_139c40::Set(int v) {
    mValue = v;
    return 1;
}