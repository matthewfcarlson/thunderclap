// CActorManager's script binding EnergyDoorSetParams (equivalent/0x00031310.cpp registers it with a Closure2 over
// <const char*, float>): stores its two arguments in the energy-door globals. Called through the closure's
// member-function pointer (thiscall: `this` unused).
#include "decls/data/game/unknown.h"

class EnergyDoorParams_244c0 {
  public:
    void Set(int a, int b);
};

void EnergyDoorParams_244c0::Set(int a, int b) {
    DAT_0048e06c = a;
    DAT_0048e070 = b;
}
