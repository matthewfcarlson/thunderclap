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
bool hulkfight::XPAction::vfunc_3(int , int ) {
    if (!(*(int *)&this->f_20))
        return (bool)(0);
    int n = (int)((Datum*)(*(void * *)&this->f_1c))->value;
    gManager->Find()->Apply("xp", n);
    return (bool)(1);
}
