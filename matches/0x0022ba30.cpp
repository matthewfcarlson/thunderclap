struct Matrix {
    unsigned int m[11];
    void Set(float);
};
extern "C" double __cdecl sin(double);
extern "C" double __cdecl cos(double);
void Matrix::Set(float angle) {
    double s = sin(angle);
    m[0] = 0x3f800000;
    m[1] = 0;
    m[2] = 0;
    m[4] = 0;
    m[8] = 0;
    double c = cos(angle);
    ((float*)this)[5] = (float)c;
    ((float*)this)[6] = (float)s;
    ((float*)this)[9] = (float)-s;
    ((float*)this)[10] = (float)c;
}