#include "gen/hulkfight.h"

struct Helper2_14ee60 {
    void* run();
};
struct Helper1_14ee60 {
    Helper2_14ee60* run();
};

void hulkfight::motion::InterruptPriorityAction::vfunc_4() {
    Helper2_14ee60* a = (*(Helper1_14ee60 * *)&this->f_20)->run();
    int* b = (int*)a->run();
    *(int*)((char*)b + 0x31c) -= *(int*)((char*)(*(void * *)&this->f_1c) + 0x14);
}
