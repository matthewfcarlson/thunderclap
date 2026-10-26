#include "decls/data/game/unknown.h"

struct Info {
    char data[24];
    unsigned int a, b;
    char extra[8];
};
extern void fetch(Info*);
double calc() {
    Info info;
    fetch(&info);
    return (float)info.a * (float)info.b - DAT_004e36a4 - DAT_004e36a0 - DAT_004e369c;
}