class Obj_12380 {
  public:
    char pad[0x40];
    float Value();
};

float Obj_12380::Value() {
    return *(float*)((char*)this + 0x40);
}
