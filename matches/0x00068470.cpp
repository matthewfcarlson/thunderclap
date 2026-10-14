class Obj_68470 {
  public:
    char pad[0x38];
    char m38;
    char Set(char v);
};

char Obj_68470::Set(char v) {
    m38 = v;
    return 1;
}