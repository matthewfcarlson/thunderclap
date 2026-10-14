struct Vec2_2a54e0 {
    float x;
    float y;
};
extern float threshold_2a54e0;
extern float reciprocal;
extern float zero_2a54e0;
extern "C" double sqrt(double);
float __fastcall Vec2Normalize(Vec2_2a54e0* v) {
    float n = v->x * v->x + v->y * v->y;
    if (n >= threshold_2a54e0) {
        float r = reciprocal / (float)sqrt(n);
        v->x *= r;
        v->y *= r;
        return reciprocal / r;
    }
    v->y = 0.0f;
    float z = zero_2a54e0;
    v->x = 0.0f;
    return z;
}