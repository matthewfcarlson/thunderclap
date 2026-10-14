class X {
  public:
    char Set(int v);
    char pad[0x78];
    char m78;
};
char X::Set(int v) {
    *(int*)&m78 = v;
    return 1;
}