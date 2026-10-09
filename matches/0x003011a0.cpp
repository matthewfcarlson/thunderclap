struct Vec3 {
    float x, y, z;
};
struct Xf {
    char pad[0x28];
    Vec3 pos;
};
struct Ent {
    char pad[0x20];
    Xf* xf;
};
struct Slot {
    char pad[0x6c];
    void Process(Ent* e, unsigned flags);
};
struct Sub {
    void Add(Vec3* v);
};
class Sim {
  public:
    Slot* mSlots;
    char pad[0x164];
    Sub mSub;
    char pad2[0x2033];
    unsigned mFlags;
    void Update(Ent* e, int i);
};
void Sim::Update(Ent* e, int i) {
    mSlots[i].Process(e, mFlags);
    if (mFlags & 8) {
        Xf* x = e->xf;
        Vec3 v;
        const Vec3& p = x->pos;
        float z = p.z + p.z;
        float y = p.y + p.y;
        float x0 = p.x + p.x;
        v.x = x0;
        v.y = y;
        v.z = z;
        mSub.Add(&v);
    }
}
