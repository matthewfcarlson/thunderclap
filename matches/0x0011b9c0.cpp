class X_11b9c0 {
  public:
    float Get();
    char pad[0x18];
};

float X_11b9c0::Get() {
    return *(float*)((char*)this + 0x18);
}
