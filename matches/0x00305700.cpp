void Scale(float s, float* src, float* dst) {
    dst[0] = s * src[0];
    dst[1] = s * src[1];
    dst[2] = s * src[2];
    dst[4] = s * src[4];
    dst[5] = s * src[5];
    dst[6] = s * src[6];
    dst[8] = s * src[8];
    dst[9] = s * src[9];
    dst[10] = s * src[10];
}