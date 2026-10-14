// STATUS: equivalent (tools/equiv.py level 3: 49 inputs, branch coverage 11/12, incomplete)
// FUN_001c2c90 @ 0x001c2c90
struct Vec3_1c2c90 {
    float x, y, z;
    void Scale(float s) {
        x = x * s;
        y = y * s;
        z = z * s;
    }
};

class PointSet_1c2c90 {
public:
    Vec3_1c2c90 *FUN_001c2c90(Vec3_1c2c90 *out);

    Vec3_1c2c90 points[32];
    unsigned int count;
};

Vec3_1c2c90 *PointSet_1c2c90::FUN_001c2c90(Vec3_1c2c90 *out)
{
    Vec3_1c2c90 sum;
    sum.x = 0.0f;
    sum.y = 0.0f;
    sum.z = 0.0f;
    if (count != 0) {
        for (unsigned int i = 0; i < count; i++) {
            sum.x += points[i].x;
            sum.y += points[i].y;
            sum.z += points[i].z;
        }
        // volatile: the original rounds the reciprocal to float before scaling the (extended) x sum
        volatile float inv = 1.0f / (float)count;
        sum.x = sum.x * inv;
        sum.y = inv * sum.y;
        sum.z = inv * sum.z;
    }
    *out = sum;
    return out;
}
