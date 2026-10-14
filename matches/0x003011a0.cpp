struct Vec3_3011a0 {
    float x, y, z;
};
struct Xf_3011a0 {
    char pad[0x28];
    Vec3_3011a0 pos;
};
struct Ent_3011a0 {
    char pad[0x20];
    Xf_3011a0* xf;
};
struct Slot_3011a0 {
    char pad[0x6c];
    void Process(Ent_3011a0* e, unsigned flags);
};
struct Sub_3011a0 {
    void Add(Vec3_3011a0* v);
};
class Sim_3011a0 {
  public:
    Slot_3011a0* mSlots;
    char pad[0x164];
    Sub_3011a0 mSub;
    char pad2[0x2033];
    unsigned mFlags;
    void Update(Ent_3011a0* e, int i);
};
void Sim_3011a0::Update(Ent_3011a0* e, int i) {
    mSlots[i].Process(e, mFlags);
    if (mFlags & 8) {
        Xf_3011a0* x = e->xf;
        Vec3_3011a0 v;
        const Vec3_3011a0& p = x->pos;
        float z = p.z + p.z;
        float y = p.y + p.y;
        float x0 = p.x + p.x;
        v.x = x0;
        v.y = y;
        v.z = z;
        mSub.Add(&v);
    }
}
