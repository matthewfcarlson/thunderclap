struct Mat_22c2b0 {
    float x0;
    float x1;
    float x2;
    float x3;
    float x4;
    float x5;
    float x6;
    float x7;
    float x8;
    float x9;
    float x10;
    float x11;
    float x12;
    float x13;
    float x14;
    float x15;
    void Transform(float*, float*);
};
void Mat_22c2b0::Transform(float* v, float* out) {
    float b = v[0] * x1 + v[1] * x5 + v[2] * x9 + x13;
    float c = v[0] * x2 + v[1] * x6 + v[2] * x10 + x14;
    float a = v[0] * x0 + v[1] * x4 + v[2] * x8 + x12;
    out[0] = a;
    out[1] = b;
    out[2] = c;
}
