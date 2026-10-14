class O_11c140 {
  public:
    char pad[0x49];
    char value;
    char Fn(char v);
};

char O_11c140::Fn(char v) {
    value = v;
    return 1;
}