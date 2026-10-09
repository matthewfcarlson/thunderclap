extern "C" double sqrt(double);
struct V {
    float pad;
    float b;
    float c;
};
struct Mat {
    float a[11];
    void Set(V* v);
};
void Mat::Set(V* v) {
    float s = (float)sqrt((double)(v->c * v->c + v->b * v->b));
    float n = 1.0f / s;
    float x = n * v->b;
    float y = n * v->c;
    a[0] = 1.0f;
    a[1] = 0.0f;
    a[5] = y;
    a[2] = 0.0f;
    a[4] = 0.0f;
    a[8] = 0.0f;
    a[6] = -x;
    a[9] = x;
    a[10] = y;
}
