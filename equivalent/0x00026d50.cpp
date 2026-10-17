// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_00026d50 @ 0x00026d50
struct Vec3 { unsigned int x, y, z; };
struct Record { char padding[0x1a84]; Vec3 position; };
__int64 __cdecl FUN_002672f0(int key, int a, int b);
struct Object {
    Record* FUN_00024280(__int64 id);
    void FUN_00026d50(Vec3* result, int key);
};
void Object::FUN_00026d50(Vec3* result, int key)
{
    __int64 id = FUN_002672f0(key, 0, 0);
    Record* record = FUN_00024280(id);
    if (record) {
        *result = record->position;
    } else {
        result->x = 0;
        result->y = 0;
        result->z = 0;
    }
}