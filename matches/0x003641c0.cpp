#include "decls/data/engine/audio.h"

#include "compat/ptr.h"
extern "C" char DAT_00423f20[];
class Stream {
  public:
    virtual void Fn();
};
void Init() {
    (*(Stream**)&DAT_004cc0cc) = (Stream*)((hulk_intptr)DAT_00423f20);
}