#include "gen/hulkfight.h"

struct Q_18f4d0 {
    void Go();
};
struct Z {
    char pad[0x128];
    Q_18f4d0* field;
};
struct Y_18f4d0 {
    Z* GetZ();
};
struct X_18f4d0 {
    Y_18f4d0* GetY();
};

bool hulkfight::motion::SimulationAction::vfunc_3(int __p0, int __p1) {
    X_18f4d0* x = (*(X_18f4d0 * *)&this->f_20);
    Y_18f4d0* y = x->GetY();
    Z* z = y->GetZ();
    Q_18f4d0* q = z->field;
    if (!q)
        return false;
    q->Go();
    return true;
}
