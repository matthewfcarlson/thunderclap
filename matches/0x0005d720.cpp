class Obj_5d720 {
  public:
    char pad[0x14];
    int value;
    char Set(int x);
};
char Obj_5d720::Set(int x) {
    value = x;
    return 1;
}