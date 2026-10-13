class C {
    char pad[0x18];
    char m;

  public:
    char Fn(char c);
};
char C::Fn(char c) {
    m = c;
    return 1;
}