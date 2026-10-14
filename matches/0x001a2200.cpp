class C_1a2200 {
  public:
    char Set(char);
    char pad[0x30];
    char m30;
};

char C_1a2200::Set(char x) {
    m30 = x;
    return 1;
}
