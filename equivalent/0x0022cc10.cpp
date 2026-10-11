// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// FUN_0022cc10 @ 0x0022cc10
struct Matrix {
    float m[4][4];
    void FUN_0022cc10(const Matrix* a, const Matrix* b);
};
void Matrix::FUN_0022cc10(const Matrix* a, const Matrix* b)
{
    Matrix result;
    for (int row = 3; row >= 0; --row) {
        for (int col = 3; col >= 0; --col) {
            result.m[row][col] = ((b->m[0][col] * a->m[row][0] + b->m[1][col] * a->m[row][1]) + a->m[row][2] * b->m[2][col]) + b->m[3][col] * a->m[row][3];
        }
    }
    *this = result;
}
