// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_001fca40 @ 0x001fca40
struct Vec3 { unsigned int x, y, z; };
struct Object { char padding[0xbc]; Vec3 position; };
Object* __stdcall FUN_001fc7f0(unsigned int id);
void __stdcall FUN_001fca40(Vec3* output, unsigned int id) {
    Object* object = FUN_001fc7f0(id);
    if (object) *output = object->position;
    else { output->x = 0; output->y = 0; output->z = 0; }
}