class Obj {
  public:
    char pad[0x1c];
    float Value();
};

float Obj::Value() {
    return *(float*)((char*)this + 0x1c);
}
