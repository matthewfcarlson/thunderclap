extern "C" const float k = 0.017453292f;
class Obj {
  public:
    char Set(float v);
    char pad[0x5c];
    float value;
};
char Obj::Set(float v) {
    value = v * k;
    int r = 1;
    return (char)r;
}