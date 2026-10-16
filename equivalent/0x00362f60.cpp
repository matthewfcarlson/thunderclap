// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00362f60 @ 0x00362f60
#include "decls/data/platform/xbox/pure3d.h"

typedef void (*Handler_362f60)();
struct Entry_362f60 {
    Handler_362f60 fn;
    int a;
    int b;
    int c;
    char pad[8];
};
struct LastEntry {
    int a, b, c, d;
};
void FUN_00330ca0();
void FUN_00330cc0();
void FUN_003333a0();
void FUN_003333b0();
void FUN_003333c0();
void FUN_003333e0();
void FUN_003333f0();
void FUN_00333400();
void FUN_00333770();
void FUN_003337d0();

void FUN_00362f60()
{
    (*(Entry_362f60*)&DAT_004d8d70).fn = FUN_003333c0;
    (*(Entry_362f60*)&DAT_004d8d88).fn = FUN_003333e0;
    (*(Entry_362f60*)&DAT_004d8da0).fn = FUN_003333f0;
    (*(Entry_362f60*)&DAT_004d8db8).fn = FUN_003337d0;
    (*(Entry_362f60*)&DAT_004d8dd0).fn = FUN_00333770;
    (*(Entry_362f60*)&DAT_004d8de8).fn = FUN_003333a0;
    (*(Entry_362f60*)&DAT_004d8e00).fn = FUN_003333b0;
    (*(Entry_362f60*)&DAT_004d8e18).fn = FUN_00333400;
    (*(Entry_362f60*)&DAT_004d8e30).fn = FUN_003333a0;
    (*(Entry_362f60*)&DAT_004d8e48).fn = FUN_003333b0;
    (*(Entry_362f60*)&DAT_004d8e60).fn = FUN_00330ca0;
    (*(Entry_362f60*)&DAT_004d8e78).fn = FUN_00330cc0;
    (*(Entry_362f60*)&DAT_004d8d70).a = 0;
    (*(Entry_362f60*)&DAT_004d8d70).b = 0;
    (*(Entry_362f60*)&DAT_004d8d70).c = 0;
    (*(Entry_362f60*)&DAT_004d8d88).a = 0;
    (*(Entry_362f60*)&DAT_004d8d88).b = 0;
    (*(Entry_362f60*)&DAT_004d8d88).c = 0;
    (*(Entry_362f60*)&DAT_004d8da0).a = 0;
    (*(Entry_362f60*)&DAT_004d8da0).b = 0;
    (*(Entry_362f60*)&DAT_004d8da0).c = 0;
    (*(Entry_362f60*)&DAT_004d8db8).a = 0;
    (*(Entry_362f60*)&DAT_004d8db8).b = 0;
    (*(Entry_362f60*)&DAT_004d8db8).c = 0;
    (*(Entry_362f60*)&DAT_004d8dd0).a = 0;
    (*(Entry_362f60*)&DAT_004d8dd0).b = 0;
    (*(Entry_362f60*)&DAT_004d8dd0).c = 0;
    (*(Entry_362f60*)&DAT_004d8de8).a = 0;
    (*(Entry_362f60*)&DAT_004d8de8).b = 0;
    (*(Entry_362f60*)&DAT_004d8de8).c = 0;
    (*(Entry_362f60*)&DAT_004d8e00).a = 0;
    (*(Entry_362f60*)&DAT_004d8e00).b = 0;
    (*(Entry_362f60*)&DAT_004d8e00).c = 0;
    (*(Entry_362f60*)&DAT_004d8e18).a = 0;
    (*(Entry_362f60*)&DAT_004d8e18).b = 0;
    (*(Entry_362f60*)&DAT_004d8e18).c = 0;
    (*(Entry_362f60*)&DAT_004d8e30).a = 0;
    (*(Entry_362f60*)&DAT_004d8e30).b = 0;
    (*(Entry_362f60*)&DAT_004d8e30).c = 0;
    (*(Entry_362f60*)&DAT_004d8e48).a = 0;
    (*(Entry_362f60*)&DAT_004d8e48).b = 0;
    (*(Entry_362f60*)&DAT_004d8e48).c = 0;
    (*(Entry_362f60*)&DAT_004d8e60).a = 0;
    (*(Entry_362f60*)&DAT_004d8e60).b = 0;
    (*(Entry_362f60*)&DAT_004d8e60).c = 0;
    (*(Entry_362f60*)&DAT_004d8e78).a = 0;
    (*(Entry_362f60*)&DAT_004d8e78).b = 0;
    (*(Entry_362f60*)&DAT_004d8e78).c = 0;
    (*(LastEntry*)&DAT_004d8e90).a = 0;
    (*(LastEntry*)&DAT_004d8e90).b = 0;
    (*(LastEntry*)&DAT_004d8e90).c = 0;
    (*(LastEntry*)&DAT_004d8e90).d = -1;
}
