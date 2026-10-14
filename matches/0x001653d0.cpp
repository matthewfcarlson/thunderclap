class X {
  public:
    char Set(char c);
    char Pad[12];
    char m;
};

char X::Set(char c) {
    m = c;
    return 1;
}
