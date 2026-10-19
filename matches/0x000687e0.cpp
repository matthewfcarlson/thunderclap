extern const float kRadianToDegree = 0.017453292f;

struct Sub_687e0 {
    char pad[0x20];
    float mAngle;
    unsigned char Set(float v);
};

unsigned char Sub_687e0::Set(float v) {
    mAngle = v * kRadianToDegree;
    return 1;
}
