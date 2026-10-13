class X {
  public:
    char pad[0x3d];
    char field;
    char Set(int v);
};

char X::Set(int v) {
    field = (char)v;
    return 1;
}