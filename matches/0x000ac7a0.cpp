class Thing_ac7a0 {
  public:
    char pad14[0x14];
    float mA;
    float mB;
    unsigned char flag;
    char pad1d[3];
    float x;
    float y;
    void Set(float a, float b);
};
extern const float one;
void Thing_ac7a0::Set(float a, float b) {
    flag = 1;
    float d = mB - mA;
    x = (one - a) * d;
    y = (one - b) * d;
}