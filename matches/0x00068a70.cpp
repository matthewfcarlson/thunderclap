class C {
  public:
    char f(float x);
};

char C::f(float x) {
    *(float*)((char*)this + 0x40) = x * 0.0174532925f;
    return 1;
}
