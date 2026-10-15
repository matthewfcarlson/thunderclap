struct Vec {
    float x, y, z;
};
class Obj {
    char pad[0x19c];
    struct {
        volatile float x;
        float y, z;
    } pos;

  public:
    void Add(const Vec* v);
};
void Obj::Add(const Vec* v) {
    pos.x += v->x;
    pos.y += v->y;
    pos.z += v->z;
}