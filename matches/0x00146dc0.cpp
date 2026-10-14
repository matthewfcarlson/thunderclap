extern const float k_146dc0 = 0.0174532925f;
class Obj_146dc0 {
  public:
    char pad[0x34];
    float m;
    bool Set(float value);
};
bool Obj_146dc0::Set(float value) {
    m = value * k_146dc0;
    return true;
}
