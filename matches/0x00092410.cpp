#include "decls/data/game/unknown.h"
// data: gItems_92410 = DAT_0049ceb0

class Obj_92410 {
  public:
    void Setup(const char*, int, int);
    void Finish(int);
};
class Host_92410 {
  public:
    Obj_92410* GetObject();
    void AddThing(Obj_92410*, const char*, int);
    void Target();
};
void Host_92410::Target() {
    Obj_92410* obj = GetObject();
    if (obj) {
        obj->Setup("constants", 1, 1);
        obj->Setup("unlockables", 0, 1);
        int i = 0;
        do {
            AddThing(obj, ((const char**)&DAT_0049ceb0)[i], i);
            ++i;
        } while (i < 0x2fe);
        obj->Finish(2);
    }
}