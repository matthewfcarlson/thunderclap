extern float kRad;
class Obj {
    char pad[0x34];
    volatile float x;
    float y;
    volatile float z;

  public:
    unsigned char Set(const volatile float* p);
};
unsigned char Obj::Set(const volatile float* p) {
    float a = p[0] * kRad;
    float b = p[1] * kRad;
    volatile float c[3];
    c[2] = p[2] * kRad;
    z = c[2];
    x = a;
    y = b;
    return 1;
}