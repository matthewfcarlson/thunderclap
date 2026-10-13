class X {
  public:
    char pad[0x18];
    float Value();
};

float X::Value() {
    return *(float*)((char*)this + 0x18);
}
