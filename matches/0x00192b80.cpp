class O_192b80 {
  public:
    char pad[0xac];
    char mB1;
    char SetB1(char b);
};
char O_192b80::SetB1(char b) {
    mB1 = b;
    return 1;
}