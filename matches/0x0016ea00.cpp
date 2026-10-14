class O_16ea00 {
  public:
    char pad[0x18];
    char m18a;
    char Set(char v);
};
char O_16ea00::Set(char v) {
    m18a = v;
    return 1;
}