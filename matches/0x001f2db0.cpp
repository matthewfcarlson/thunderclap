#include "gen/global.h"
#include "decls/data/game/global.h"
// data: g_checker = DAT_004e3690, g_size_1f2db0 = DAT_004c6f4c

class Checker_1f2db0 {
  public:
    bool check(int);
};
int __cdecl make_stream(int, int);
int __cdecl create_stream(int, int, int, int, int, int, int);
class StreamPlayerAllocator_1f2db0 {
  public:
    virtual int vfunc_0(int, int, int, int);
    virtual int vfunc_1();
};

int CSoundStreamAllocator::vfunc_0(int a, int b, int c, int d) {
    int x = make_stream(d, DAT_004c6f4c);
    if (!(*(Checker_1f2db0**)&DAT_004e3690)->check(x))
        return 0;
    return create_stream(c, 0, b, x, 0, 0, 1);
}
