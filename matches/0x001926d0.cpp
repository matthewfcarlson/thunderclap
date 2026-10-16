class Obj {
  public:
    char pad[0x38];
    float angle;
    char Set(float degrees);
};
char Obj::Set(float degrees) {
    angle = degrees * 0.017453292f;
    return 1;
}