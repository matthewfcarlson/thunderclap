#include "gen/physics.h"

struct Mat_2fb7a0 {
    float m[16];
    void Fn(void* a, void* b);
};
struct Prov_2fb7a0;
struct Prov_2fb7a0 {
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual Mat_2fb7a0* Get(int id);
};
struct Mid_2fb7a0 {
    char pad[0x18];
    Prov_2fb7a0* prov;
    Mat_2fb7a0* Get(int id) { return prov->Get(id); }
};

void physics::CollisionOBB::vfunc_13() {
    (*(char *)&this->f_19) = 1;
    Mat_2fb7a0 m = *(*(Mid_2fb7a0 * *)&this->f_10)->Get(this->f_08);
    m.Fn((*(char (*)[12])&this->f_94), (*(char (*)[12])&this->f_54));
    m.Fn((*(char (*)[12])&this->f_a0), (*(char (*)[12])&this->f_60));
    m.Fn((*(char (*)[12])&this->f_ac), (*(char (*)[12])&this->f_6c));
}
