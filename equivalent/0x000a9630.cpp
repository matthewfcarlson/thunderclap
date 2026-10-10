// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 24/24)
// FUN_000a9630 @ 0x000a9630
extern "C" double sqrt(double);
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern "C" unsigned int DAT_004d9968;

extern const float DAT_004218a8;
extern const float DAT_004218ac;
extern const float DAT_004218b8;
extern const float DAT_004218bc;

struct Sphere {
    float x, y, z, radius;
};
struct Effect {
    void FUN_001c5130(float a, float b);
};
struct SubObj {
    char pad[0x11c];
    Effect* effect;
};
struct Attach {
    char pad[0x10];
    Effect* effect;
};
struct Item {
    char pad[0x124];
    Attach* attach;
    bool FUN_000359e0(Sphere* out);
    SubObj* FUN_00035ef0(int index);
};
struct List {
    char pad[0xc];
    int count;
    Item* FUN_00024190(int index);
    bool FUN_00024300(Item* item);
    bool FUN_000242d0(Item* item);
};
struct Holder {
    char pad[0x20];
    List* list;
};
struct Vec3 {
    float x, y, z;
};
struct Camera {
    char pad[0x30];
    Vec3 pos;
};
class Manager {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual Camera* vfunc_14();
    void FUN_000a9630(Holder* holder);
};
void Manager::FUN_000a9630(Holder* holder) {
    volatile unsigned int cookie = DAT_004d9968;
    int count = holder->list->count;
    for (int i = 0; i < count; i++) {
        Item* item = holder->list->FUN_00024190(i);
        if (!item)
            continue;
        if (holder->list->FUN_00024300(item))
            continue;
        Sphere s;
        if (!item->FUN_000359e0(&s))
            continue;
        Camera* cam = vfunc_14();
        Vec3 c = cam->pos;
        float dx = s.x - c.x;
        float dy = s.y - c.y;
        float dz = s.z - c.z;
        double dist = sqrt((double)(dx * dx + dy * dy + dz * dz));
        if (!(dist < s.radius))
            continue;
        float a = DAT_004218a8;
        float b = DAT_004218b8;
        if (holder->list->FUN_000242d0(item)) {
            a = DAT_004218ac;
            b = DAT_004218bc;
        }
        if (item->attach && item->attach->effect)
            item->attach->effect->FUN_001c5130(a, b);
        for (int j = 0; j < 8; j++) {
            SubObj* sub = item->FUN_00035ef0(j);
            if (sub && sub->effect)
                sub->effect->FUN_001c5130(a, b);
        }
    }
    __security_check_cookie(cookie);
}
