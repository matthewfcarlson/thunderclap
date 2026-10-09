// Same code shape as 0x0030e6c0 (propagated; names are from that function)
struct CollisionWall {
    char pad[0x54];
};
CollisionWall* __fastcall CollisionWall_vfunc_4(CollisionWall* self) {
    return (CollisionWall*)((char*)self + 0x54);
}