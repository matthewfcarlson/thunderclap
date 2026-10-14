extern "C" const float k_1929b0 = 0.017453292f;
class Obj_1929b0 {
  public:
    char Set(float v);
    char pad[0x5c];
    float value;
};
char Obj_1929b0::Set(float v) {
    value = v * k_1929b0;
    int r = 1;
    return (char)r;
}