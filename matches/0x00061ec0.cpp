const float k = 0.0174533f;
class Obj {
  public:
    char pad[0x28];
    float angle;
    char Set(float x);
};
char Obj::Set(float x) {
    angle = x * k;
    return 1;
}