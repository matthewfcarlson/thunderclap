extern "C" double sqrt(double);
struct Vec {
    float x, y;
};
struct Mat {
    float a[11];
    void Init(const Vec* v);
};
void Mat::Init(const Vec* v) {
    float vx = v->x;
    float n = 1.0f / (float)sqrt(v->y * v->y + vx * vx);
    float x = n * v->x;
    float y = n * v->y;
    a[0] = x;
    a[2] = 0;
    a[6] = 0;
    a[8] = 0;
    a[1] = y;
    a[9] = 0;
    a[10] = 1.0f;
    a[4] = -y;
    a[5] = x;
}