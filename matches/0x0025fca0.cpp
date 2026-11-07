// A name against a sequence event type's name (records.h SeqEventTypeHead): strcmp of the two texts.
#include "decls/data/records.h"
extern "C" int strcmp(const char*, const char*);
class Text {
  public:
    const char* FUN_0023fb00();
};
extern "C" int FUN_0025fca0(void * a, void * b) {
    return strcmp(((Text *)a)->FUN_0023fb00(), ((Text *)&((SeqEventTypeHead *)b)->name)->FUN_0023fb00());
}
