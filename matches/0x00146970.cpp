class Obj_146970 {
  public:
    char pad[0x10];
    float value;
    bool Fn(float degrees);
};
bool Obj_146970::Fn(float degrees) {
    value = degrees * 0.017453292519943295f;
    return true;
}