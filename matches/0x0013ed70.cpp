const float RADIAN_FACTOR = 0.0174533f;
class Obj {
  public:
    char Set(float v);
    char pad[0x24];
};
char Obj::Set(float v) {
    *(float*)((char*)this + 0x24) = v * RADIAN_FACTOR;
    return 1;
}
