class T {
  public:
    char pad[0x14];
    char mVal;
    char Set(char c);
};

char T::Set(char c) {
    mVal = c;
    return 1;
}