// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00062430 @ 0x00062430
struct Vector3 { float x, y, z; };
struct Angles { char padding[0x38]; float x, y, z; void FUN_00062430(Vector3 *out); };
void Angles::FUN_00062430(Vector3 *out) {
    out->x = x * 57.2958f;
    out->y = y * 57.2958f;
    out->z = z * 57.2958f;
}