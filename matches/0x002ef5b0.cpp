#include "gen/physics.h"

struct Vec_2ef5b0 {
    float x, y, z;
};
struct Matrix_2ef5b0 {
    float m[16];
    void FUN_0022cdb0();
    void FUN_0022c2b0(const Vec_2ef5b0* input, Vec_2ef5b0* output);
};
struct Position_2ef5b0 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual Vec_2ef5b0* slot4();
    char pad[0x15];
    unsigned char dirty;
};
struct Node_2ef5b0 {
    char pad0[0x20];
    Position_2ef5b0* position;
    char pad1[0x44];
    unsigned char dirty;
};

void physics::SimState::FUN_002ef5b0(void* __p0, void* __p1) { const Matrix_2ef5b0 * first = (const Matrix_2ef5b0 *)__p0; Matrix_2ef5b0 * second = (Matrix_2ef5b0 *)__p1;

    Matrix_2ef5b0 inverse = *first;
    inverse.FUN_0022cdb0();
    Vec_2ef5b0 intermediate, delta;
    inverse.FUN_0022c2b0((*(Node_2ef5b0 * *)&this->f_74)->position->slot4(), &intermediate);
    second->FUN_0022c2b0(&intermediate, &delta);
    Vec_2ef5b0* original = (*(Node_2ef5b0 * *)&this->f_74)->position->slot4();
    Node_2ef5b0* current = (*(Node_2ef5b0 * *)&this->f_74);
    delta.x = delta.x - original->x;
    delta.y = delta.y - original->y;
    delta.z = delta.z - original->z;
    current->dirty = 1;
    Vec_2ef5b0* result = current->position->slot4();
    result->x = delta.x + result->x;
    result->y = delta.y + result->y;
    result->z = delta.z + result->z;
    current->position->dirty = 0;
}
