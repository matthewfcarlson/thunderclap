#include "gen/pure3d.h"

class Obj_2a7ec0 {
  public:
    void Fn(void*, unsigned char*);
};
struct A_2a7ec0 {
    char pad[0x28];
    int count;
};
struct B_2a7ec0 {
    char pad[0x3c];
    unsigned char* bytes;
};
struct C_2a7ec0 {
    char pad[0x44];
    B_2a7ec0* b;
};

void pure3d::CompDrawVisibilityAnimationController::vfunc_7() {
    int n = (*(A_2a7ec0 * *)&this->f_3c)->count;
    for (int i = 0; i < n; i++) {
        if ((*(unsigned char * *)&this->f_50)[i] != 0xff && (*(Obj_2a7ec0 ** *)&this->f_44)[i]) {
            unsigned char x;
            (*(Obj_2a7ec0 ** *)&this->f_44)[i]->Fn((*(void * *)&this->f_34), &x);
            (*(C_2a7ec0 * *)&this->f_40)->b->bytes[(*(unsigned char * *)&this->f_50)[i] * 12] = x;
        }
    }
}
