struct Vec {
    int x, y, z;
};
struct Entry {
    Vec v;
    char pad[28];
};
class Thing {
    char pad[0x1d4];
    Entry entries[8];

  public:
    Vec* Get(Vec* out, int index);
};
Vec* Thing::Get(Vec* out, int index) {
    if (index >= 0 && index < 8)
        *out = entries[index].v;
    else {
        out->x = 0;
        out->y = 0;
        out->z = 0;
    }
    return out;
}