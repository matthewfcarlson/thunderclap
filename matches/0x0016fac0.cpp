class Obj_16fac0 {
  public:
    char pad[0x10];
    char value;
    char Set(char v);
};
char Obj_16fac0::Set(char v) {
    value = v;
    return 1;
}
