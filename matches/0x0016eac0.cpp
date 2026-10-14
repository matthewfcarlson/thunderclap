class C {
  public:
    char pad[12];
    unsigned int m;
    char Fn(unsigned int x);
};
char C::Fn(unsigned int x) {
    m = x;
    return 1;
}
