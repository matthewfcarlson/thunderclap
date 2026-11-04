const float rads = 0.017453292f;

class Obj_48200 {
  public:
    char SetAngle_00048200(float deg);
};

char Obj_48200::SetAngle_00048200(float deg) {
    *(float*)((char*)this + 0x0c) = deg * rads;
    return 1;
}
