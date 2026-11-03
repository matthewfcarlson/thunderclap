#include "gen/owners.h"
struct X_2df7d0 {
};
struct C_2df7d0 {
    char pad[0x5c];
    X_2df7d0* member;
    void target();
};
void C_2df7d0::target() {
    ((owners::Thing_2c7070 *)member)->FUN_002c7070();
}