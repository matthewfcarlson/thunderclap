class Obj {
  public:
    char pad[0x24];
    float angle;
    char Set(float x);
};
char Obj::Set(float x) {
    angle = x * 0.017453292f;
    return 1;
}