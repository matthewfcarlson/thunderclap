struct Vec_687c0 {
    int x;
    int y;
    int z;
};
class Obj_687c0 {
  public:
    char pad[0x14];
    Vec_687c0 v;
    char Set(Vec_687c0* p);
};
char Obj_687c0::Set(Vec_687c0* p) {
    v.x = p->x;
    v.y = p->y;
    v.z = p->z;
    return 1;
}
