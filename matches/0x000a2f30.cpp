#include "gen/global.h"

struct Local_a2f30 {
    char pad[12];
};
struct Helper_a2f30 {
    bool Read(Local_a2f30*);
};
struct CChaseCamera_nv_a2f30 {
    void Apply(float, int);
};
extern float __cdecl GetVal(Local_a2f30*);
extern float __cdecl Transform(float);

void CChaseCamera::FUN_000a2f30(int arg) {
    Local_a2f30 local;
    if ((*(Helper_a2f30 * *)&this->f_350) && (*(Helper_a2f30 * *)&this->f_350)->Read(&local)) {
        float x = GetVal(&local);
        x = Transform(x + 180.0f);
        ((CChaseCamera_nv_a2f30*)this)->Apply(x, arg);
    }
}
