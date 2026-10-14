class Obj_14ce50 {
  public:
    char Pad[0x1c];
    int Value;
    char Set(int x);
};
char Obj_14ce50::Set(int x) {
    Value = x;
    return 1;
}