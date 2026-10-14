// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 12/12)
// FUN_00221f90 @ 0x00221f90
extern "C" int __cdecl __isnan(double value);
struct MatrixData {
    float matrix[4][4];
    float extra[4];
    bool FUN_00221f90();
};
bool MatrixData::FUN_00221f90() {
    for (int row = 0; row < 4; ++row) {
        for (int col = 0; col < 4; ++col) {
            if (__isnan(matrix[row][col])) return false;
        }
    }
    if (__isnan(extra[0])) return false;
    if (__isnan(extra[1])) return false;
    if (__isnan(extra[2])) return false;
    return __isnan(extra[3]) == 0;
}