#include "compat/ptr.h"
extern "C" char DAT_00421a04[];
struct RoomLoader {
    int vft;
    int a;
    int b;
    int c;
    int d;
    int e;
    RoomLoader(int arg);
};
RoomLoader::RoomLoader(int arg) {
    a = 0;
    c = 0;
    d = 0;
    b = 0x60000701;
    vft = ((hulk_intptr)DAT_00421a04);
    e = arg;
}