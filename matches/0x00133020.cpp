class Obj_133020 {
  public:
    char pad[0x10];
    int value;
    char Set(int v);
};
char Obj_133020::Set(int v) {
    value = v;
    return 1;
}
