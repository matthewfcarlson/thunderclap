#include "gen/pure3d.h"

struct Stack_31e9b0 {
    int pad0;
    int pad1;
    int top;
    char* data;
};

struct StateBase {
    virtual void Restore(void* ctx);
};

void pure3d::pddiBaseContext::vfunc_88(unsigned char mask) {
    if (mask & 1) {
        (*(Stack_31e9b0 * *)&this->f_38)->top--;
        (*(StateBase * *)&this->f_4c) = (StateBase*)((*(Stack_31e9b0 * *)&this->f_38)->data + (*(Stack_31e9b0 * *)&this->f_38)->top * 0x1c);
        (*(StateBase * *)&this->f_4c)->Restore(this);
    }
    if (mask & 2) {
        (*(Stack_31e9b0 * *)&this->f_34)->top--;
        (*(StateBase * *)&this->f_48) = (StateBase*)((*(Stack_31e9b0 * *)&this->f_34)->data + (*(Stack_31e9b0 * *)&this->f_34)->top * 0x34);
        (*(StateBase * *)&this->f_48)->Restore(this);
    }
    if (mask & 4) {
        (*(Stack_31e9b0 * *)&this->f_3c)->top--;
        (*(StateBase * *)&this->f_50) = (StateBase*)((*(Stack_31e9b0 * *)&this->f_3c)->data + (*(Stack_31e9b0 * *)&this->f_3c)->top * 0x3ec);
        (*(StateBase * *)&this->f_50)->Restore(this);
    }
    if (mask & 8) {
        (*(Stack_31e9b0 * *)&this->f_40)->top--;
        (*(StateBase * *)&this->f_54) = (StateBase*)((*(Stack_31e9b0 * *)&this->f_40)->data + (*(Stack_31e9b0 * *)&this->f_40)->top * 20);
        (*(StateBase * *)&this->f_54)->Restore(this);
    }
    if (mask & 0x10) {
        (*(Stack_31e9b0 * *)&this->f_44)->top--;
        (*(StateBase * *)&this->f_58) = (StateBase*)((*(Stack_31e9b0 * *)&this->f_44)->data + (*(Stack_31e9b0 * *)&this->f_44)->top * 36);
        (*(StateBase * *)&this->f_58)->Restore(this);
    }
}
