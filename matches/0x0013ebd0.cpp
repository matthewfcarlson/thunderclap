class Obj {
  public:
    char pad[0x3c];
    float angle;
    char Set(float x);
};
char Obj::Set(float x) {
    angle = x * 0.017453292f;
    return 1;
}