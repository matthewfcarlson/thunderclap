class Obj_48220 {
  public:
    char pad[0x10];
    float rad;
    unsigned char SetArc_00048220(float deg);
};
unsigned char Obj_48220::SetArc_00048220(float deg) {
    rad = deg * 0.017453292f;
    return 1;
}