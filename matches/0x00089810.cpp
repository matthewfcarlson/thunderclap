#include "gen/owners.h"
struct Base_89810 {
};
struct Obj_89810 {
    char pad[0x80];
    void FUN_00089810(int);
};
void Obj_89810::FUN_00089810(int a0) {
    ((owners::Obj_88fe0 *)(((Base_89810*)((char*)this + 0x80))))->FUN_00088fe0((unsigned int)a0);
}