class X {
  public:
    float Get();
    char pad[0x18];
};

float X::Get() {
    return *(float*)((char*)this + 0x18);
}
