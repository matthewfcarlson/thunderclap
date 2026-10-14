class Obj_11920 {
  public:
    char pad[0x1c];
    float Value();
};

float Obj_11920::Value() {
    return *(float*)((char*)this + 0x1c);
}
