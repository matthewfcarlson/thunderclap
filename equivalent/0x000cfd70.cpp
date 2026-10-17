// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Closure2<HUDOverlay,void,int,math::Vector>::vfunc_2 @ 0x000cfd70
struct Vector { float x, y, z; };
struct HUDOverlay {};
struct Closure2 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void*, const void*, void*);
    char padding[0x18];
    void (HUDOverlay::*method)(int, Vector);
    HUDOverlay* object;
};
void Closure2::vfunc_2(void*, const void* args, void*) {
    const int* words = (const int*)args;
    Vector vector;
    vector.x = *(const float*)(words + 1);
    vector.y = *(const float*)(words + 2);
    vector.z = *(const float*)(words + 3);
    (object->*method)(words[0], vector);
}