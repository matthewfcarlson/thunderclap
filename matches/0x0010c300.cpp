class T_10c300 {
  public:
    char pad[0x14];
    char mVal;
    char SetNumberofAttachedProps_0010c300(char c);
};

char T_10c300::SetNumberofAttachedProps_0010c300(char c) {
    mVal = c;
    return 1;
}