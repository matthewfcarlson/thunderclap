#include "decls/data/game/unknown.h"
// data: gRandom = DAT_004de948

typedef float(__cdecl* RandomFn)();
class Obj_de1d0 {
  public:
    char pad[0x2c];
    float second;
    char pad2[4];
    float first;
    void Update();
};
void Obj_de1d0::Update() {
    first += (*(RandomFn*)&DAT_004de948)();
    second += (*(RandomFn*)&DAT_004de948)();
}