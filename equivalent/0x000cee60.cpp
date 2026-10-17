// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method2<HUDOverlay,void,int,math::Vector>::vfunc_2 @ 0x000cee60
struct Vector { float x, y, z; };
struct HUDOverlay { void FUN_000cee60(int, Vector); };
struct Arguments { int index; Vector position; };
struct Method2 {
    char reserved[0x1c];
    void (HUDOverlay::*method)(int, Vector);
    void target(HUDOverlay *owner, const Arguments *args, int unused);
};
void Method2::target(HUDOverlay *owner, const Arguments *args, int unused) {
    (owner->*method)(args->index, args->position);
}