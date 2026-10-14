class Obj_133530 {
  public:
    char pad[0x1c];
    float f;
    char Set(float x);
};
char Obj_133530::Set(float x) {
    f = x * 0.017453292519943295f;
    return 1;
}
