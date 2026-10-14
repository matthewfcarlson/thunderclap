class C_12e090 {
  public:
    char Pad[0x18];
    int Value;
    char Set(int v);
};
char C_12e090::Set(int v) {
    Value = v;
    return 1;
}