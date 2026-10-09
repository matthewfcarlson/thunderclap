struct Vec3 { float x,y,z; };
class C { public: char pad[0x14]; Vec3* data; void f(int index, Vec3* src, float t); };
void C::f(int index, Vec3* src, float t) {
    Vec3* p = data + index;
    p->x = (src->x - p->x) * t + p->x;
    p->y = (src->y - p->y) * t + p->y;
    p->z = (src->z - p->z) * t + p->z;
}