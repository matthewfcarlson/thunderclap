class X_12c00 {
  public:
    char pad[0x18];
    float Value();
};

float X_12c00::Value() {
    return *(float*)((char*)this + 0x18);
}
