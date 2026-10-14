class Obj_16eb90 {
  public:
    char Pad[0x30];
    char Value;
    char Set(char x);
};

char Obj_16eb90::Set(char x) {
    Value = x;
    return 1;
}