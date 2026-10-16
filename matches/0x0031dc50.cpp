#include "gen/pure3d.h"

struct V {
    int x, y, z;
};

void pure3d::pddiBaseContext::vfunc_45(int index, void* __p1) { V * out = (V *)__p1;

    if (index < 8) {
        char* p = (char*)(*(void ** *)&this->f_50) + index * 0x7c + 4;
        int a = *(int*)p;
        V* q = out;
        q->x = a;
        q->y = *(int*)(p + 4);
        q->z = *(int*)(p + 8);
    } else {
        out->z = 0;
        out->y = 0;
        out->x = 0;
    }
}
