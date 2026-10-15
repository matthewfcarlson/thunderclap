struct Vec {
    float x, y, z;
};
class Obj {
    char pad[0x1a8];
    volatile float x;
    float y, z;

  public:
    void Add(Vec* v);
};
void Obj::Add(Vec* v) {
    x = x + v->x;
    y = v->y + y;
    z = v->z + z;
}