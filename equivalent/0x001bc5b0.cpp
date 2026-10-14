// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_001bc5b0 @ 0x001bc5b0
struct Vec3_1bc5b0 {
    float x, y, z;
};

class View {
public:
    void FUN_001c19a0();
};

class Camera {
public:
    View *view;
    Vec3_1bc5b0 *FUN_001c39b0();
    Vec3_1bc5b0 *FUN_001c39a0();
};

Camera *FUN_001c3d90();
void FUN_001bc530(Vec3_1bc5b0 *v);

// equiv-conv: FUN_001bc5b0 edi stack
void FUN_001bc5b0(Vec3_1bc5b0 *pos, float a)
{
    Camera *cam = FUN_001c3d90();
    cam->view->FUN_001c19a0();
    Vec3_1bc5b0 *d = cam->FUN_001c39b0();
    Vec3_1bc5b0 v;
    v = *pos;
    v.x = a * d->x + v.x;
    v.y = a * d->y + v.y;
    v.z = a * d->z + v.z;
    FUN_001bc530(&v);
    float neg = -a;
    v = *pos;
    v.x = neg * d->x + v.x;
    v.y = neg * d->y + v.y;
    v.z = neg * d->z + v.z;
    FUN_001bc530(&v);
    d = cam->FUN_001c39a0();
    v = *pos;
    v.x = a * d->x + v.x;
    v.y = a * d->y + v.y;
    v.z = a * d->z + v.z;
    FUN_001bc530(&v);
    v = *pos;
    v.x = neg * d->x + v.x;
    v.y = neg * d->y + v.y;
    v.z = neg * d->z + v.z;
    FUN_001bc530(&v);
}
