class Obj {
  public:
    char pad[0x1c];
    char mVal;
    char Set(char c);
};
char Obj::Set(char c) {
    mVal = c;
    return 1;
}
