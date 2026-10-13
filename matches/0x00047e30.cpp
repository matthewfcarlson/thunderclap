class X {
  public:
    char Pad[12];
    int Value;
    char Method(int arg);
};

char X::Method(int arg) {
    Value = arg;
    return 1;
}
