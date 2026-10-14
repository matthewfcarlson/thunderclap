class O {
  public:
    char pad[0x178];
    char m178;
    char Set(char c);
};

char O::Set(char c) {
    m178 = c;
    return 1;
}
