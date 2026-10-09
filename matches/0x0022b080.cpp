void Fn(float* o, const float* a, const float* b) {
    float x = a[3] * b[1] + b[3] * a[1] + a[2] * b[0] - b[2] * a[0];
    float y = a[3] * b[2] + a[0] * b[1] + a[2] * b[3] - b[0] * a[1];
    float w = a[3] * b[3] - a[0] * b[0] - a[1] * b[1] - a[2] * b[2];
    float z = b[3] * a[0] + b[2] * a[1] + a[3] * b[0] - a[2] * b[1];
    o[0] = z;
    o[1] = x;
    o[2] = y;
    o[3] = w;
}
