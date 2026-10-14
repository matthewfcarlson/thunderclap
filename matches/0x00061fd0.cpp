class Obj_61fd0 {
  public:
    char pad[0x10];
    int field;
    char Set(int value);
};
char Obj_61fd0::Set(int value) {
    field = value;
    return 1;
}
