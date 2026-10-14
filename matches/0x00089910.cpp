class Obj_89910 {
  public:
    char pad[0x104];
    float Value();
};

float Obj_89910::Value() {
    return *(float*)((char*)this + 0x104);
}
