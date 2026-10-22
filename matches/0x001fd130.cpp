#include "compat/ptr.h"
class Elem_1fd130 {
  public:
    char pad[0x458];
    int mFlag;
    char pad2[0xc70 - 0x45c];
    bool Check(void* p);
    void Do(void* p);
};

class CTriggerVolumeManager_1fd130 {
  public:
    char pad[0x234];
    int mArray;
    void Target(void* p2, void* p3);
};

void CTriggerVolumeManager_1fd130::Target(void* p2, void* p3) {
    for (hulk_intptr i = 0; i < 0x6380; i += 0xc70) {
        Elem_1fd130* e = (Elem_1fd130*)(mArray + i);
        if (e->mFlag != 0) {
            if (((Elem_1fd130*)(mArray + i))->Check(p3)) {
                ((Elem_1fd130*)(mArray + i))->Do(p2);
            }
        }
    }
}
