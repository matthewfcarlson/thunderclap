class Obj {
  public:
    char pad[0x18];
    float angle;
    char Set(float x);
};
char Obj::Set(float x) {
    angle = x * 0.017453292f;
    return 1;
}