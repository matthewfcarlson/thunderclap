class O {
  public:
    char pad[0x49];
    char value;
    char Fn(char v);
};

char O::Fn(char v) {
    value = v;
    return 1;
}