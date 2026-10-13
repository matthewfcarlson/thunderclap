class C {
  public:
    char Pad[0x18];
    int Value;
    char Set(int v);
};
char C::Set(int v) {
    Value = v;
    return 1;
}