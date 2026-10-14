class O {
  public:
    char pad[0x18];
    char m18a;
    char Set(char v);
};
char O::Set(char v) {
    m18a = v;
    return 1;
}