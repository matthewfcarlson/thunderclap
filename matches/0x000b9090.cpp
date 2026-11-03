#include "gen/owners.h"
extern "C" void __cdecl CallA(int);
extern "C" int __cdecl CallB();
extern "C" int __cdecl CallC();


void owners::Target_b9090::FUN_000b9090(int value) {
    CallA(value);
    if (CallB() == 0) {
        if (CallC() == 0) {
            state = 4;
        }
    }
}