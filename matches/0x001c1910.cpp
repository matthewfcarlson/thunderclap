struct Vec {
    int x, y, z;
};
class Obj {
    char pad[0xf4];
    Vec values[1];

  public:
    void Set(int index, const Vec* value);
};
void Obj::Set(int index, const Vec* value) {
    Vec* p = &values[index];
    p->x = value->x;
    p->y = value->y;
    p->z = value->z;
}