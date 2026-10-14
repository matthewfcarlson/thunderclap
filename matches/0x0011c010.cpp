extern const float k = 0.0174533f;

class Obj {
  public:
    char pad[0x18];
    float mValue;
    char Set(float f);
};

char Obj::Set(float f) {
    mValue = f * k;
    return 1;
}
