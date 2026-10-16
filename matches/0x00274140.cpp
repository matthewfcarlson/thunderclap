#include "gen/core.h"

struct Sub_274140 {
    virtual void a();
    virtual void b();
};
struct File_274140 {
    char pad0[4];
    Sub_274140 sub;
    char pad1[0xc];
    int state;
    char pad2[0x124 - 0x18];
    int position;
};

int core::FileSetPositionRequest::vfunc_1() {
    (*(File_274140 * *)&this->f_08)->position = this->f_0c;
    (*(File_274140 * *)&this->f_08)->sub.a();
    (*(File_274140 * *)&this->f_08)->state = 0;
    (*(File_274140 * *)&this->f_08)->sub.b();
    return 1;
}
