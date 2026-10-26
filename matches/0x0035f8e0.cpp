#include "decls/data/engine/audio.h"
// data: gName = DAT_004e61f0

class Name {
  public:
    Name(const char*, int);
    ~Name();
};
extern "C" int __cdecl atexit(void(__cdecl*)());
void __cdecl cleanup();
void init() {
    (*(Name*)&DAT_004e61f0).Name::Name("?Name?", 0);
    atexit(cleanup);
}