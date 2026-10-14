extern "C" double sqrt(double);
extern const float gSmall, gOne, gZero;
struct Vec_22d110 {
    float x, y, z;
    float Normalize();
};
float Vec_22d110::Normalize() {
    float n = z * z + y * y + x * x;
    if (n >= gSmall) {
        float s = sqrt(n);
        s = gOne / s;
        x *= s;
        y *= s;
        z *= s;
        return gOne / s;
    }
    float result = gZero;
    x = y = z = 0;
    return result;
}