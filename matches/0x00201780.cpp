#include "decls/data/game/global.h"
// data: gCount = DAT_004c8fb8, gPairs = DAT_004e5928, gValues = DAT_004c8fa4

extern "C" __int64 __cdecl FUN_002672f0(int, int, int);
extern "C" int __cdecl FUN_00201780(int x) {
    __int64 n = FUN_002672f0(x, 0, 0);
    int answer = -1;
    for (int i = 0; i < DAT_004c8fb8; ++i) {
        if (((__int64*)&DAT_004e5928)[i] == n) {
            answer = DAT_004c8fa4[i];
            break;
        }
    }
    return answer;
}