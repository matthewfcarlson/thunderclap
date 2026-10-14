const float rads = 0.0174533f;

class Obj_48200 {
  public:
    char Set(float deg);
};

char Obj_48200::Set(float deg) {
    *(float*)((char*)this + 0x0c) = deg * rads;
    return 1;
}
