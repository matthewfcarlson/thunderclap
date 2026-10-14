class C {
  public:
    char Pad[0x10];
    int m;
    char Set(int);
};
char C::Set(int x) {
    m = x;
    return 1;
}
