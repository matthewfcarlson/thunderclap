class O_10c620 {
  public:
    char pad[0x14];
    char m14;
    char SetOnlySetAtEnd_0010c620(char c);
};

char O_10c620::SetOnlySetAtEnd_0010c620(char c) {
    m14 = c;
    return 1;
}