extern const float gZero_1c4500;
class Obj_1c4500 {
    char pad0[0x18];
    float a;
    char pad1[0x0c];
    float b;

  public:
    bool Check();
};
bool Obj_1c4500::Check() {
    return b != 0.0f && a != 0.0f;
}