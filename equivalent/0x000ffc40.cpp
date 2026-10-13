// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// CHand2HandAgent::vfunc_16 @ 0x000ffc40
struct CHand2HandAgent {
    char pad0[0x7a];
    unsigned char active;
    char pad1[0xb0-0x7b];
    float ax, ay, az;
    float bx, by, bz;
    char pad2[0x150-0xc8];
    float resultX, resultY, resultZ;
    void vfunc_16();
};
void CHand2HandAgent::vfunc_16() {
    float negativeX = -bx;
    float negativeZ = -bz;
    if ((bx * az + negativeZ * ax + ay * 0.0f) >
        (negativeX * az + bz * ax + ay * 0.0f)) {
        resultX = bz;
        resultZ = negativeX;
    } else {
        resultX = negativeZ;
        resultZ = bx;
    }
    resultY = 0.0f;
    if ((az * bz + ay * by + ax * bx) > 0.8f) {
        resultX = 0.0f;
        resultY = 0.0f;
        resultZ = 0.0f;
        active = 0;
    }
}
