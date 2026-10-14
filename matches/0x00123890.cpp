class X {
  public:
    unsigned char F(float a);
};
unsigned char X::F(float a) {
    float c = 0.0174532925199433f;
    *(float*)((char*)this + 0xc) = a * c;
    return 1;
}
