class Obj {
  public:
    char pad[0xa4];
    float angle;
    char Set(float x);
};
char Obj::Set(float x) {
    angle = x * 0.017453292519943295f;
    return 1;
}