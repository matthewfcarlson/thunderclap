extern const float gzero;
extern const float gone;
struct Entry {
    unsigned int id;
    float w;
    float v;
};
class Obj {
  public:
    char pad[0x30];
    unsigned int limit;
    char pad34[0x12ec - 0x34];
    unsigned int count;
    Entry e[1];
    void Add(unsigned int, float, float);
};
void Obj::Add(unsigned int id, float w, float v) {
    if (w <= gzero)
        return;
    if (id >= limit)
        return;
    unsigned int i;
    for (i = 0; i < count; i++) {
        if (e[i].id == id) {
            float nw = w + e[i].w;
            e[i].w = nw;
            float t = w / nw;
            e[i].v = t * v + (gone - t) * e[i].v;
            return;
        }
    }
    e[count].id = id;
    e[count].w = w;
    e[count].v = v;
    count++;
}
