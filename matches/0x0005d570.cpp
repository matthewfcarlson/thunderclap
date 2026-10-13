class C {
  public:
    char Fn(char arg);
    char m[0x3c];
    char m3c;
};
char C::Fn(char arg) {
    m3c = arg;
    return 1;
}
