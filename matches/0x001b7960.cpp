#include "compat/ptr.h"
struct ThisWrap_001b7960 {
    void FUN_001b7360(int a, int b);
    void FUN_001b7960(hulk_intptr a, int b);
};
void ThisWrap_001b7960::FUN_001b7960(hulk_intptr a, int b) {
    this->FUN_001b7360(a, 3000);
}