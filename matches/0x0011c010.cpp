extern const float k_11c010 = 0.0174533f;

class Obj_11c010 {
  public:
    char pad[0x18];
    float mValue;
    char Set(float f);
};

char Obj_11c010::Set(float f) {
    mValue = f * k_11c010;
    return 1;
}
