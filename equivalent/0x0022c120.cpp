// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0022c120 @ 0x0022c120
struct Matrix {
    float m[16];
    void FUN_0022c0b0();
    void FUN_0022c120();
};

// Inverts a rigid transform in place: transposes the rotation, then maps the negated translation through it.
void Matrix::FUN_0022c120()
{
    float tx = -m[12];
    float ty = -m[13];
    float tz = -m[14];
    FUN_0022c0b0();
    m[11] = 0.0f;
    m[7] = 0.0f;
    m[3] = 0.0f;
    m[15] = 1.0f;
    m[12] = (tz * m[8] + ty * m[4]) + tx * m[0];
    m[13] = (tz * m[9] + ty * m[5]) + tx * m[1];
    m[14] = (tz * m[10] + ty * m[6]) + tx * m[2];
}
