class T {
  public:
    char pad[0x3c];
    char m3c;
    char Set(char c);
};

char T::Set(char c) {
    m3c = c;
    return 1;
}
