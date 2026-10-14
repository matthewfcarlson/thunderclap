// cl-flags: /O2
const float RAD_CONST = 0.0174533f;

class Obj_123550 {
  public:
    char pad[0x10];
    float mAngle;
    char Set(float deg);
};

char Obj_123550::Set(float deg) {
    mAngle = deg * RAD_CONST;
    return 1;
}
