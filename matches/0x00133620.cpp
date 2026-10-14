class T_133620 {
  public:
    char pad[0x3c];
    char m3c;
    char Set(char c);
};

char T_133620::Set(char c) {
    m3c = c;
    return 1;
}
