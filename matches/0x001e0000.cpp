#include "gen/global.h"

struct CSPManager_1e0000 {
    void FUN_001e0000_callback(int, float, float, float);
};
struct Arguments {
    int id;
    float first;
    float second;
    float third;
};

template <> void Method4<CSPManager, void, int, float, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { CSPManager_1e0000 * manager = (CSPManager_1e0000 *)__p0; Arguments * arguments = (Arguments *)__p1; void * unused = (void *)__p2;

    int* p = (int*)arguments;
    int id = *p++;
    float first = *(float*)p++;
    float second = *(float*)p++;
    float third = *(float*)p++;
    (manager->*(*(void (CSPManager_1e0000::**)(int, float, float, float))&this->f_1c))(id, first, second, third);
}
