#include "decls/data/engine/audio.h"
#include "decls/data/game/global.h"
// data: ending = DAT_00422518, fmt = DAT_004298a8

extern "C" char __cdecl output(const char*, const char*, ...);
class Handler {
  public:
    char check(char**);
};
char work(char** text, const char* value, Handler* handler) {
    char* s = *text;
    if (output(s, DAT_004298a8, value) && handler->check(text)) {
        s = *text;
        return output(s, DAT_00422518);
    }
    return 0;
}
