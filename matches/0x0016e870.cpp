class X_16e870 {
  public:
    char Fn(float x);
};

char X_16e870::Fn(float x) {
    *(float*)((char*)this + 0x44) = x * 0.0174532925f;
    return 1;
}