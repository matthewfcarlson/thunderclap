struct Sub_e3d70 {
    void fn(int);
};
class Obj_e3d70 {
  public:
    char pad0[0xa4];
    int value;
    char pad1[0x495c - 0xa8];
    int width;
    int height;
    char tail[1];
    void update(int x, int y, int z);
};
void Obj_e3d70::update(int x, int y, int z) {
    if (x < width && y < height) {
        Sub_e3d70* p = (Sub_e3d70*)((char*)this + 0x15c + (y + x * 8) * 0x24);
        p->fn(z);
        *(int*)p = value;
    }
}