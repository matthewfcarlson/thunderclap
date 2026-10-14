class C_68a70 {
  public:
    char f(float x);
};

char C_68a70::f(float x) {
    *(float*)((char*)this + 0x40) = x * 0.0174532925f;
    return 1;
}
