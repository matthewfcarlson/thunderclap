#include "decls/data/engine/audio.h"
// data: first = DAT_00429aac, registry = DAT_004e6800, second = DAT_00429270

#include "compat/ptr.h"
#include "decls/address.h"
typedef __int64 I64;
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl FUN_00364390();
class Registry {
  public:
    void FUN_002584d0(I64*, I64*, int, int);
};
void __cdecl target() {
    HULK_SIZE32(AudioSeqActionChannelSends, 0x10);
    I64 a = FUN_002672f0(DAT_00429aac, 0, 0);
    I64 b = FUN_002672f0(DAT_00429270, 0, 0);
    (*(Registry*)&DAT_004e6800).FUN_002584d0(&b, &a, (int)sizeof(AudioSeqActionChannelSends), (int)__alignof(AudioSeqActionChannelSends));
    atexit(FUN_00364390);
}