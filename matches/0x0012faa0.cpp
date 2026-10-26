#include "compat/ptr.h"
#include "gen/hulkfight.h"

namespace hulkfight {
} // namespace hulkfight
struct Datum {
    char pad[16];
    float value;
};
class Result {
  public:
    void Apply(const char*, int);
};
class Manager {
  public:
    Result* Find();
};
extern Manager* gManager;
bool hulkfight::XPAction::vfunc_3(hulk_intptr , hulk_intptr ) {
    if (!(*(int *)&this->f_20))
        return (bool)(0);
    int n = (int)(__int64)((Datum*)(*(void * *)&this->f_1c))->value;
    gManager->Find()->Apply("xp", n);
    return (bool)(1);
}
