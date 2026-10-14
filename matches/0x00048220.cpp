class Obj_48220 {
  public:
    char pad[0x10];
    float rad;
    unsigned char Set(float deg);
};
unsigned char Obj_48220::Set(float deg) {
    rad = deg * 0.017453292f;
    return 1;
}