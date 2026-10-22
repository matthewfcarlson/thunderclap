// FUN_002f3db0 @ 0x002f3db0
struct Rec_2f3db0 { int w[6]; Rec_2f3db0* FUN_00298530(void* a, void* b); };
struct Inner_2f3db0 { char pad[0x24]; Rec_2f3db0 rec; };
struct CollisionMesh_2f3db0 {
    char pad0[0x44]; Inner_2f3db0* inner;
    char pad1[0xcc - 0x48]; char flag;
    Rec_2f3db0 Get();
};
Rec_2f3db0 CollisionMesh_2f3db0::Get() {
    if (flag) {
        Rec_2f3db0 tmp;
        tmp.FUN_00298530((char*)this + 0x4c, &inner->rec);
        return tmp;
    }
    return inner->rec;
}
