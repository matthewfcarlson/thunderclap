class Obj {
  public:
    char pad[0x18];
    float angle;
    char Set(float deg);
};

char Obj::Set(float deg) {
    angle = deg * 0.017453292f;
    return 1;
}
