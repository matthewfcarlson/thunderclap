#include "compat/ptr.h"
#include "gen/hulkfight.h"

class HelperA_18d280 {
  public:
    void* run();
};
class HelperB_18d280 {
  public:
    void* run();
};

bool hulkfight::motion::TimerSetAction::vfunc_3(hulk_intptr , hulk_intptr ) {
    int i = *(int*)((char*)(*(void * *)&this->f_1c) + 0x10);
    if (i >= 0 && i < 14) {
        void* x = ((HelperA_18d280*)(*(void * *)&this->f_20))->run();
        x = ((HelperB_18d280*)x)->run();
        *(int*)((char*)x + 0x1e60 + i * 4) = *(int*)((char*)(*(void * *)&this->f_1c) + 0x14);
    }
    return (bool)(0);
}
