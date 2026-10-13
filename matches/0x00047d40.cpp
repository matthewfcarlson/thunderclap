class C {
  public:
    char pad0[12];
    char m1;
    char Set(char v);
};
char C::Set(char v) {
    m1 = v;
    return 1;
}
