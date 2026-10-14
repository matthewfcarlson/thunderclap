class Obj_16f7f0 {
  public:
    char pad[0x44];
    int value;
    char Set(int x);
};
char Obj_16f7f0::Set(int x) {
    value = x;
    return 1;
}
