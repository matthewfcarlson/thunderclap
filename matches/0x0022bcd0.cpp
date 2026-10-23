extern "C" double __cdecl sin(double);
extern "C" double __cdecl cos(double);
struct Matrix {
    float m[3][4];
    void FUN_0022bcd0(float x, float y, float z);
};
void Matrix::FUN_0022bcd0(float x, float y, float z) {
    double sx = sin(x), cx = cos(x);
    float sy = (float)sin(y);
    double cy = cos(y);
    float sz = (float)sin(z), cz = (float)cos(z);
    float a = (float)(cy * cx), b = (float)(sy * sx), c = (float)(cy * sx), d = (float)(sy * cx);
    m[0][0] = (float)(cz * cy);
    m[0][1] = a * sz + b;
    m[0][2] = c * sz - d;
    m[1][0] = -sz;
    m[1][1] = (float)(cz * cx);
    m[1][2] = (float)(cz * sx);
    m[2][0] = cz * sy;
    m[2][1] = d * sz - c;
    m[2][2] = b * sz + a;
}