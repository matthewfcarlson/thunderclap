class Obj {
  public:
    char Pad[0x30];
    char Value;
    char Set(char x);
};

char Obj::Set(char x) {
    Value = x;
    return 1;
}