const float RADIAN_FACTOR = 0.0174533f;
class Obj_13ed70 {
  public:
    char Set(float v);
    char pad[0x24];
};
char Obj_13ed70::Set(float v) {
    *(float*)((char*)this + 0x24) = v * RADIAN_FACTOR;
    return 1;
}
