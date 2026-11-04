class X_12e000 {
  public:
    char pad[0x10];
    char m10;
    char SetLocked_0012e000(char v);
};

char X_12e000::SetLocked_0012e000(char v) {
    m10 = v;
    return 1;
}
