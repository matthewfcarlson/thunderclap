class Obj {
  public:
    char Pad[0x20];
    char Value;
    char Set(char c);
};

char Obj::Set(char c) {
    Value = c;
    return 1;
}