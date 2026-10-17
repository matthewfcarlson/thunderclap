// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_001fc9f0 @ 0x001fc9f0
struct Result { int x, y, z; };
struct Object { char pad[0xb0]; Result value; };
Object* __stdcall FUN_001fc7f0(int id);
void __stdcall FUN_001fc9f0(Result* out, int id) {
    Object* object = FUN_001fc7f0(id);
    if (object) *out = object->value;
    else { out->x = 0; out->y = 0; out->z = 0; }
}