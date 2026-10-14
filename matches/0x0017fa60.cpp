extern const float DEG_TO_RAD = 0.017453292519943295f;

struct X_17fa60 {
    char pad[0x3c];
    float mVal;
    char Set(float v);
};

char X_17fa60::Set(float v) {
    mVal = v * DEG_TO_RAD;
    return 1;
}
