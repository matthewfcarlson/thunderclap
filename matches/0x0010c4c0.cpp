class C {
  public:
    char pad[12];
    int mValue;
    char Set(int x);
};
char C::Set(int x) {
    mValue = x;
    return 1;
}
