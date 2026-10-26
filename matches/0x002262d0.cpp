#include "decls/data/game/global.h"
// data: gone = DAT_003f32dc, gzero = DAT_003f32e0

#include "compat/ptr.h"
struct Entry_2262d0 {
    unsigned int id;
    float w;
    float v;
};
class Obj_2262d0 {
  public:
    char pad[0x30];
    unsigned int limit;
    char pad34[0x12ec - 0x34];
    unsigned int count;
    Entry_2262d0 e[1];
    void Add(unsigned int, float, float);
};
void Obj_2262d0::Add(unsigned int id, float w, float v) {
    if (w <= DAT_003f32e0)
        return;
    if (id >= limit)
        return;
    unsigned int i;
    for (i = 0; i < count; i++) {
        if (e[i].id == id) {
            hulk_freg nw = w + e[i].w;
            e[i].w = nw;
            hulk_freg t = w / nw;
            e[i].v = t * v + (DAT_003f32dc - t) * e[i].v;
            return;
        }
    }
    e[count].id = id;
    e[count].w = w;
    e[count].v = v;
    count++;
}
