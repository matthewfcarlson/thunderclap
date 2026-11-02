#include "decls/data/game/unknown.h"

struct Info {
    char data[24];
    unsigned int a, b;
    char extra[8];
};
extern "C" void FUN_00240ca0(Info*);
double calc() {
    Info info;
    FUN_00240ca0(&info);
    return (float)info.a * (float)info.b - DAT_004e36a4 - DAT_004e36a0 - DAT_004e369c;
}