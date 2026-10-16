#include "gen/hulkfight.h"

struct Result_147b80 {
    char pad[0x1e58];
    float value;
    int flag;
};
struct HelperA_147b80 {
    HelperA_147b80* f();
};
struct HelperB_147b80 {
    Result_147b80* g();
};
class Action_147b80 {
  public:
    char pad[0x20];
};

bool hulkfight::motion::GrappleStruggleAction::vfunc_3(int , int ) {
    HelperA_147b80* a = *(HelperA_147b80**)((char*)this + 0x20);
    HelperA_147b80* b = a->f();
    Result_147b80* r = ((HelperB_147b80*)b)->g();
    r->flag = 1;
    r->value = 0.5f;
    return true;
}
