class Obj_68800 {
  public:
    char pad[0x24];
    int value;
    unsigned char Set(int x);
};
unsigned char Obj_68800::Set(int x) {
    value = x;
    return 1;
}
