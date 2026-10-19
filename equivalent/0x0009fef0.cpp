// STATUS: equivalent (tools/equiv.py level 3: 19772 inputs, branch coverage 0/0)
// FUN_0009fef0 @ 0x0009fef0
// FUN_0009fef0 @ 0x0009fef0
struct Vec_9fef0 { float x,y,z; float FUN_0022d110(); };
extern "C" double __cdecl sin(double);
extern "C" double __cdecl cos(double);
Vec_9fef0* __cdecl FUN_0009fef0(Vec_9fef0* out, const Vec_9fef0* axis, const Vec_9fef0* v, float degrees) {
    double dot = (double)axis->x*v->x + (double)v->z*axis->z + (double)v->y*axis->y;
    volatile float px = (float)(dot*axis->x);
    volatile float py = (float)(dot*axis->y);
    Vec_9fef0 tangent;
    tangent.x = v->x-px;
    tangent.y = v->y-py;
    tangent.z = (float)(v->z-dot*axis->z);
    tangent.FUN_0022d110();
    double angle = degrees*0.01745329238474369f;
    double s = sin(angle);
    volatile float sx = (float)(tangent.x*s);
    volatile float sy = (float)(tangent.y*s);
    double sz = tangent.z*s;
    double c = cos(angle);
    double cx = c*axis->x;
    volatile float cy = (float)(c*axis->y);
    volatile float cz = (float)(c*axis->z);
    out->x = (float)(cx+sx);
    out->y = cy+sy;
    out->z = (float)(cz+sz);
    return out;
}
