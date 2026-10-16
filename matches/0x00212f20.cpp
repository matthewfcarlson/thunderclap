#include "decls/data/engine/unknown.h"

extern "C" char* FUN_00212f20(int, int index) {
    if (index == -1)
        return (char*)((int)((char*)&DAT_004265fc));
    return *(char**)(((int)((char*)&DAT_00426948)) + index * 4);
}