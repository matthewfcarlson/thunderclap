#include "gen/global.h"

class Notifier {
  public:
    void Notify(int);
};

void TextSelector::vfunc_26(int index, int value) {
    *(int*)((char*)this + (index + 7) * 0x38) = value;
    if ((*(Notifier * *)&this->f_1d94))
        (*(Notifier * *)&this->f_1d94)->Notify(this->f_154);
    vfunc_0();
}
