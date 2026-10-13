class C {
  public:
    char pad[0x20];
    char m20;
    char Set(char value);
};

char C::Set(char value) {
    m20 = value;
    return 1;
}