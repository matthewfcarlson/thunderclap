#include "gen/global.h"

struct Vec3_10ad90 {
    float x, y, z;
};
struct List_10ad90 {
    char pad[0xc];
    int count;
    int GetItem(int i);
    bool IsSkipped(int id);
};
struct Agent_10ad90 {
    char pad[0x20];
    List_10ad90* list;
};
float FUN_0010ac60(int ex, int item, float w, Vec3_10ad90* out);

bool CSeparationBehaviour::vfunc_3(int __p0, int ex, void* __p2, int p5, int p6) { Agent_10ad90 * a = (Agent_10ad90 *)__p0; Vec3_10ad90 * out = (Vec3_10ad90 *)__p2;

    int n = a->list->count;
    int i = 0;
    out->z = 0.0f;
    out->y = 0.0f;
    out->x = 0.0f;
    if (0 < n) {
        do {
            int item = a->list->GetItem(i);
            if (!a->list->IsSkipped(item) && item != ex) {
                Vec3_10ad90 tmp;
                FUN_0010ac60(ex, item, 1.0f, &tmp);
                out->x += tmp.x;
                out->y += tmp.y;
                out->z += tmp.z;
            }
            ++i;
        } while (i < n);
    }
    if (this->f_0c) {
        float w = this->f_08;
        out->x = w * out->x;
        out->y = w * out->y;
        out->z = w * out->z;
    }
    return true;
}
