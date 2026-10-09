struct Vec2 { float x; float y; };
extern float threshold;
extern float reciprocal;
extern float zero;
extern "C" double sqrt(double);
float __fastcall Vec2Normalize(Vec2 *v) {
    float n = v->x * v->x + v->y * v->y;
    if (n >= threshold) {
        float r = reciprocal / (float)sqrt(n);
        v->x *= r;
        v->y *= r;
        return reciprocal / r;
    }
    v->y = 0.0f;
    float z = zero;
    v->x = 0.0f;
    return z;
}