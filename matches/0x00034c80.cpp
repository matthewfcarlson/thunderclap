#include "decls/data/game/hulkfight.h"

struct Wrapper {
    void FUN_001c5080(float, int);
    void FUN_00034c80(int value);
};
void Wrapper::FUN_00034c80(int value) {
    FUN_001c5080((*(float*)&DAT_00421894), value);
}