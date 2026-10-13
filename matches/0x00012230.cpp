class X {
    char pad[0x20];

  public:
    float Value();
};
float X::Value() {
    return *(float*)((char*)this + 0x20);
}
