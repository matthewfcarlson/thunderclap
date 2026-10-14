class O_10c620 {
  public:
    char pad[0x14];
    char m14;
    char Set(char c);
};

char O_10c620::Set(char c) {
    m14 = c;
    return 1;
}