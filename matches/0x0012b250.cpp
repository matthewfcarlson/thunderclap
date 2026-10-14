class Obj_12b250 {
  public:
    char Pad[0x20];
    char Value;
    char Set(char c);
};

char Obj_12b250::Set(char c) {
    Value = c;
    return 1;
}