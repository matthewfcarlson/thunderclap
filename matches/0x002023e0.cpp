extern "C" char DAT_004259f8[];
struct Head_2023e0 {
    int x, y, z;
    char d, e;
    void C(int);
};
struct Obj_2023e0 {
    int v;
    void A();
    void B(int);
};
class CWorldCollisionManager {
  public:
    void* vf;
    char pad4[4];
    Head_2023e0 head;
    int value;
    char pad1c[4];
    Obj_2023e0 part;
    char pad24[4];
    char flag;
};
extern int global64;
CWorldCollisionManager* __fastcall FUN_002023e0(CWorldCollisionManager* s, void*) {
    Head_2023e0* h = &s->head;
    s->vf = (void*)((int)DAT_004259f8);
    h->x = 0;
    h->y = 0;
    h->z = 0;
    h->d = 0;
    h->e = 0;
    s->part.A();
    s->value = (int)0xc61c4000;
    s->part.B(0);
    s->flag = 0;
    h->C(global64);
    return s;
}
