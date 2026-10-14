class X_12230 {
    char pad[0x20];

  public:
    float Value();
};
float X_12230::Value() {
    return *(float*)((char*)this + 0x20);
}
