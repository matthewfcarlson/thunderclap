class C {
  public:
    char pad[0x98];
    int m;
    char Set(int x);
};
char C::Set(int x) {
    m = x;
    return 1;
}
