class Obj {
  public:
    char pad[0x104];
    float Value();
};

float Obj::Value() {
    return *(float*)((char*)this + 0x104);
}
