class T_10c300 {
  public:
    char pad[0x14];
    char mVal;
    char Set(char c);
};

char T_10c300::Set(char c) {
    mVal = c;
    return 1;
}