class Obj_68220 {
  public:
    char pad[0x68];
    int field;
    char Set(int value);
};

char Obj_68220::Set(int value) {
    field = value;
    return 1;
}
