class O {
  public:
    char pad[12];
    char m;
    char Fn(char c);
};
char O::Fn(char c) {
    m = c;
    return 1;
}