class O {
  public:
    char pad[0xac];
    char mB1;
    char SetB1(char b);
};
char O::SetB1(char b) {
    mB1 = b;
    return 1;
}