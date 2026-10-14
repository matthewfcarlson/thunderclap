class Obj_68160 {
  public:
    char pad[0x18];
    float angle;
    char Set(float deg);
};

char Obj_68160::Set(float deg) {
    angle = deg * 0.017453292f;
    return 1;
}
