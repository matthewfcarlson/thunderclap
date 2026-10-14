class Obj_146f90 {
  public:
    char pad[0x40];
    float value;
    char Set(float deg);
};
char Obj_146f90::Set(float deg) {
    value = deg * 0.01745329238474369f;
    return 1;
}
