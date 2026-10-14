extern const float k = 0.0174533f;
class Obj {
  public:
    char Set(float x);
};
char Obj::Set(float x) {
    *(float*)((char*)this + 0x14) = x * k;
    return 1;
}