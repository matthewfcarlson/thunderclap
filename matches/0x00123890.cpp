class X_123890 {
  public:
    unsigned char F(float a);
};
unsigned char X_123890::F(float a) {
    float c = 0.0174532925199433f;
    *(float*)((char*)this + 0xc) = a * c;
    return 1;
}
