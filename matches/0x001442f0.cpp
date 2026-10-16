#include "gen/hulkfight.h"

class Action_1442f0 {
    char pad[0x20];

  public:
    int value;
};
struct Receiver_1442f0 {
    void call(int);
};
struct GlobalObj_1442f0 {
    char pad[0x58];
    Receiver_1442f0* member;
};
extern GlobalObj_1442f0* gObj_1442f0;

void hulkfight::motion::SlowMotionAction::vfunc_4() {
    gObj_1442f0->member->call(this->f_20);
}
