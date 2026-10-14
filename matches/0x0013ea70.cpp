class Obj_13ea70 {
  public:
    char pad[0x18];
    int value;
    char Set(int v);
};
char Obj_13ea70::Set(int v) {
    value = v;
    return 1;
}
