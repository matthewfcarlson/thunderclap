// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00305520 @ 0x00305520
struct Vector3_305520 { float x, y, z; };
struct Row_305520 { float x, y, z, w; };
struct Matrix { Row_305520 rows[4]; };
void __cdecl FUN_00305520(const Vector3_305520* rotation, Matrix* matrix)
{
    Matrix original = *matrix;
    for (int i = 0; i < 3; ++i) {
        matrix->rows[i].x = (original.rows[i].x - original.rows[i].y * rotation->z) + original.rows[i].z * rotation->y;
        matrix->rows[i].y = (original.rows[i].x * rotation->z + original.rows[i].y) - original.rows[i].z * rotation->x;
        matrix->rows[i].z = (original.rows[i].z - original.rows[i].x * rotation->y) + original.rows[i].y * rotation->x;
    }
}
