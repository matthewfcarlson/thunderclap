#include "gen/fight.h"

extern float zero_2373e0;
struct Receiver_2373e0 {
    void run(int, int, int);
};

void fight::OpportunityAction::vfunc_4() {
    if (this->f_28 < zero_2373e0 && (*(Receiver_2373e0 * *)&this->f_4c))
        (*(Receiver_2373e0 * *)&this->f_4c)->run(this->f_38, this->f_3c, this->f_30);
}
