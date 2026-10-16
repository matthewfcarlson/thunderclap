extern const float zero;
class Obj {
  public:
    char pad[0x7d0];
    float value;
    void Set(float x);
};
void Obj::Set(float x) {
    if (x >= zero)
        value = x;
}