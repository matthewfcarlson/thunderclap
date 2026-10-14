class C {
  public:
    char pad[0x114];
    int value;
    char Set(int x);
};
char C::Set(int x) {
    value = x;
    return 1;
}
