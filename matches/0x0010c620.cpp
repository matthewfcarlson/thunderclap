class O {
  public:
    char pad[0x14];
    char m14;
    char Set(char c);
};

char O::Set(char c) {
    m14 = c;
    return 1;
}