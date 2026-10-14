class Obj {
  public:
    char pad[0x76];
    char mVal;
    char Set(char value);
};

char Obj::Set(char value) {
    mVal = value;
    return 1;
}
