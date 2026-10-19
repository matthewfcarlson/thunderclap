float* Scale(float* out, float scalar, const float* in) {
    float a = scalar * in[2];
    float b = scalar * in[1];
    float c = scalar * in[0];
    out[0] = c;
    out[1] = b;
    out[2] = a;
    return out;
}