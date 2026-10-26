#include "gen/fight.h"
#include "decls/data/game/global.h"
// data: zero_2373e0 = DAT_003f32e0

struct Receiver_2373e0 {
    void run(int, int, int);
};

void fight::OpportunityAction::vfunc_4() {
    if (this->f_28 < (*(float*)&DAT_003f32e0) && (*(Receiver_2373e0 * *)&this->f_4c))
        (*(Receiver_2373e0 * *)&this->f_4c)->run(this->f_38, this->f_3c, this->f_30);
}
