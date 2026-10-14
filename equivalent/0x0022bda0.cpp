// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0022bda0 @ 0x0022bda0
extern "C" double __cdecl sin(double);
extern "C" double __cdecl cos(double);

class Matrix {
public:
    float m[3][4];
    void FUN_0022bda0(float a, float b, float c);
};

// Builds the 3x3 rotation block from three Euler angles.
void Matrix::FUN_0022bda0(float a, float b, float c)
{
    double sa = sin(a);
    double ca = cos(a);
    double sb = sin(b);
    volatile float cb = (float)cos(b);
    double sc = sin(c);
    double cc = cos(c);
    volatile float t1 = (float)(sc * sb);
    volatile float t2 = (float)(cc * cb);
    m[0][0] = (float)(t1 * sa + t2);
    m[0][1] = (float)(sc * ca);
    m[0][2] = (float)((sc * cb) * sa - cc * sb);
    m[1][0] = (float)((cc * sb) * sa - sc * cb);
    m[1][1] = (float)(cc * ca);
    m[1][2] = (float)(t2 * sa + t1);
    m[2][0] = (float)(sb * ca);
    m[2][1] = (float)(-sa);
    m[2][2] = (float)(cb * ca);
}
