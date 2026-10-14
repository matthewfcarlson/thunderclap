class Obj_1803e0 {
  public:
    char pad[12];
    int field;
    char Set(int value);
};
char Obj_1803e0::Set(int value) {
    field = value;
    return 1;
}
