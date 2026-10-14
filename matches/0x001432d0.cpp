class C_1432d0 {
  public:
    char pad[0x20];
    char m20;
    char Set(char value);
};

char C_1432d0::Set(char value) {
    m20 = value;
    return 1;
}