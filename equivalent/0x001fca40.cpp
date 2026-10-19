// STATUS: equivalent (tools/equiv.py level 3: 20005 inputs, branch coverage 2/2)
// FUN_001fca40 @ 0x001fca40
struct Vec3 { unsigned int x, y, z; };
struct Object { char padding[0xbc]; Vec3 position; };
struct ThisWrap_001fca40 {
    Object* FUN_001fc7f0(unsigned int id);
    void FUN_001fca40(Vec3* output, unsigned int id);
};
void ThisWrap_001fca40::FUN_001fca40(Vec3* output, unsigned int id) {
    Object* object = this->FUN_001fc7f0(id);
    if (object) *output = object->position;
    else { output->x = 0; output->y = 0; output->z = 0; }
}