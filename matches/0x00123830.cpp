class X {
  public:
    char pad[12];
    int m;
    unsigned char Fn(int v);
};
unsigned char X::Fn(int v) {
    m = v;
    return 1;
}