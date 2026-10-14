extern const float kRadianToDegree = 0.0174533f;

struct Sub {
    char pad[0x20];
    float mAngle;
    unsigned char Set(float v);
};

unsigned char Sub::Set(float v) {
    mAngle = v * kRadianToDegree;
    return 1;
}
