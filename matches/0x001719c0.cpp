#include "compat/ptr.h"
#include "gen/hulkfight.h"

class HelperB_1719c0 {
  public:
    void* run();
};
class HelperA_1719c0 {
  public:
    HelperB_1719c0* run();
};
struct State_1719c0 {
    char pad[0x14];
    unsigned char active;
};

bool hulkfight::motion::ChargeClearAction::vfunc_3(hulk_intptr , hulk_intptr ) {
    if (((State_1719c0*)(*(void * *)&this->f_1c))->active) {
        HelperB_1719c0* x = (*(HelperA_1719c0 * *)&this->f_20)->run();
        void* result = x->run();
        *(int*)((char*)result + 0x1e58) = 0;
        return (bool)(0);
    }
    return (bool)(1);
}
