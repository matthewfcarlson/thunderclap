class Obj {
  public:
    char SetAngle(float x);
    char pad[0x30];
};

char Obj::SetAngle(float x) {
    *(float*)((char*)this + 0x30) = x * (3.14159265358979323846f / 180.0f);
    return 1;
}
