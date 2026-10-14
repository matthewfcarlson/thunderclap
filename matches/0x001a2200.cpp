class C {
  public:
    char Set(char);
    char pad[0x30];
    char m30;
};

char C::Set(char x) {
    m30 = x;
    return 1;
}
