inline float Abs(float x) {
    *(unsigned*)&x &= 0x7fffffff;
    return x;
}
bool F(const float* a, const float* b, float e) {
    if (Abs(a[0] - b[0]) > e)
        return false;
    else if (Abs(a[5] - b[5]) > e)
        return false;
    else if (Abs(a[10] - b[10]) > e)
        return false;
    else
        return true;
}
