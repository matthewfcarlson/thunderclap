class C {
  public:
    char pad[0x34];
    int value;
    unsigned char Set(int x);
};
unsigned char C::Set(int x) {
    value = x;
    return 1;
}
