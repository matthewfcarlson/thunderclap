const float rads = 0.0174533f;

class Obj {
  public:
    char Set(float deg);
};

char Obj::Set(float deg) {
    *(float*)((char*)this + 0x0c) = deg * rads;
    return 1;
}
