class X_11c0f0 {
  public:
    char pad[0x3d];
    char field;
    char Set(int v);
};

char X_11c0f0::Set(int v) {
    field = (char)v;
    return 1;
}