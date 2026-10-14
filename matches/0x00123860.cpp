class Obj_123860 {
  public:
    char pad[0x14];
    char value;
    char Set(char v);
};
char Obj_123860::Set(char v) {
    value = v;
    return 1;
}
