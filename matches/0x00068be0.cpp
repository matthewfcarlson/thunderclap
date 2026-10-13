class C {
  public:
    char fn(int x);
    char pad[0x14];
    int m14;
};
char C::fn(int x) {
    m14 = x;
    return 1;
}