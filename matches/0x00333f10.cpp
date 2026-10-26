#include "decls/data/engine/core.h"
#include "decls/data/platform/xbox/movie.h"

extern void* v0[];
extern void* v1_333f10[];
extern void* v2_333f10[];
extern void* v3_333f10[];
extern void* v4_333f10[];
extern "C" void _ReadWriteBarrier();
class PlayerBink_333f10;
void FUN_002705f0() throw();
class PlayerBink_333f10 {
  public:
    void* p0;
    void* p1;
    int id;
    int m0c;
    int a, b, c, d;
    float f;
    char x, y;
    PlayerBink_333f10() throw();
};
PlayerBink_333f10::PlayerBink_333f10() throw() {
    *(void* volatile*)&p0 = v0;
    *(void* volatile*)&p1 = v1_333f10;
    id = DAT_004cdbb0;
    FUN_002705f0();
    *(void* volatile*)&p1 = v2_333f10;
    m0c = 0;
    FUN_002705f0();
    *(void* volatile*)&p0 = v3_333f10;
    p1 = v4_333f10;
    _ReadWriteBarrier();
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    x = 0;
    y = 0;
    f = 1.0f;
    (*(PlayerBink_333f10**)&DAT_00555ba4) = this;
}
