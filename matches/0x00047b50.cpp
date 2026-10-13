class C {
  public:
    char pad[0x18];
    int mValue;
    char Set(int v);
};

char C::Set(int v) {
    mValue = v;
    return 1;
}
