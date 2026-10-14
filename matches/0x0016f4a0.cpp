extern const float RAD = 0.017453292519943295f;
class Obj_16f4a0 {
  public:
    bool Set(float a);
};
bool Obj_16f4a0::Set(float a) {
    float r = a * RAD;
    *(float*)((char*)this + 0x3c) = r;
    return true;
}
