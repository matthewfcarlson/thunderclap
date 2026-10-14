class Thing_123920 {
  public:
    char Pad[12];
    char mVal;
    char Set(char c);
};

char Thing_123920::Set(char c) {
    mVal = c;
    return 1;
}