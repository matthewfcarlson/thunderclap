class O {
  public:
    char pad[0x51];
    char m51;
    char Set(char c);
};
char O::Set(char c) {
    m51 = c;
    return 1;
}
