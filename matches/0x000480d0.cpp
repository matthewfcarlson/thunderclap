class C {
  public:
    char pad[0x14];
    char m14;
    char Set(char a);
};
char C::Set(char a) {
    m14 = a;
    return 1;
}
