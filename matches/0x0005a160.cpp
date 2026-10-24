class Obj_5a160 {
  public:
    char SetAngle(float x);
    char pad[0x30];
};

char Obj_5a160::SetAngle(float x) {
    *(float*)((char*)this + 0x30) = x * 0.017453292f;
    return 1;
}
