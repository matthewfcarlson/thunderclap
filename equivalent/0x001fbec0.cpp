// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_001fbec0 @ 0x001fbec0
struct Vec3 { unsigned int x, y, z; };
struct Entity {
    char pad[0xb0];
    Vec3 primary;
    Vec3 fallback;
    char pad2[4];
    unsigned char flags;
    void FUN_001fbec0(Vec3 *result);
};
void Entity::FUN_001fbec0(Vec3 *result) {
    unsigned int x = primary.x;
    unsigned int y = primary.y;
    unsigned int z = primary.z;
    unsigned char bits = flags;
    if (!(bits & 1)) x = fallback.x;
    if (!(bits & 2)) y = fallback.y;
    if (!(bits & 4)) z = fallback.z;
    result->x = x;
    result->y = y;
    result->z = z;
}