class Obj {
  public:
    char m0[0x74];
    char m74;
    char Set(char value);
};

char Obj::Set(char value) {
    m74 = value;
    return 1;
}
