struct Vec3_2fb640 {
    unsigned int x, y, z;
};
namespace physics {
struct CollisionVolume {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual Vec3_2fb640* vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14(CollisionVolume*);
    char pad04[0x34];
    unsigned int flags;
    char pad3c[12];
    unsigned int scaleX, scaleY, scaleZ;
    Vec3_2fb640 axisX, axisY, axisZ;
    char pad78[16];
    unsigned int worldScaleX, worldScaleY, worldScaleZ;
    Vec3_2fb640 worldAxisX, worldAxisY, worldAxisZ;
};
struct CollisionOBB : CollisionVolume {
    void vfunc_14(CollisionVolume* destination);
};
void CollisionOBB::vfunc_14(CollisionVolume* destination) {
    CollisionVolume::vfunc_14(destination);
    Vec3_2fb640* sourceVector = vfunc_4();
    Vec3_2fb640* targetVector = destination->vfunc_4();
    targetVector->x = sourceVector->x;
    targetVector->y = sourceVector->y;
    targetVector->z = sourceVector->z;
    destination->axisX.x = axisX.x;
    destination->axisX.y = axisX.y;
    destination->axisX.z = axisX.z;
    destination->worldAxisX.x = worldAxisX.x;
    destination->worldAxisX.y = worldAxisX.y;
    destination->worldAxisX.z = worldAxisX.z;
    destination->scaleX = scaleX;
    destination->worldScaleX = worldScaleX;
    destination->axisY.x = axisY.x;
    destination->axisY.y = axisY.y;
    destination->axisY.z = axisY.z;
    destination->worldAxisY.x = worldAxisY.x;
    destination->worldAxisY.y = worldAxisY.y;
    destination->worldAxisY.z = worldAxisY.z;
    destination->scaleY = scaleY;
    destination->worldScaleY = worldScaleY;
    destination->axisZ.x = axisZ.x;
    destination->axisZ.y = axisZ.y;
    destination->axisZ.z = axisZ.z;
    destination->worldAxisZ.x = worldAxisZ.x;
    destination->worldAxisZ.y = worldAxisZ.y;
    destination->worldAxisZ.z = worldAxisZ.z;
    destination->scaleZ = scaleZ;
    destination->worldScaleZ = worldScaleZ;
    destination->flags = flags;
}
} // namespace physics
