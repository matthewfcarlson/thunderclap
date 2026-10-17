// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_003015c0 @ 0x003015c0
struct Vec3 { float x,y,z; };
struct Object {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual Vec3* slot4();
    char pad[0x30];
    float offset;
    float normalX, normalY, normalZ;
};
float __cdecl FUN_003015c0(Object* a, Object* b) {
    Vec3* first = a->slot4();
    Vec3* second = b->slot4();
    return ((second->x - first->x) * a->normalX + (second->y - first->y) * a->normalY + (second->z - first->z) * a->normalZ) - b->offset;
}