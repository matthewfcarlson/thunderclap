class Obj {
  public:
    char pad[0x80];
    float angle;
    char Set(float x);
};
char Obj::Set(float x) {
    angle = x * 0.017453292519943295f;
    return 1;
}