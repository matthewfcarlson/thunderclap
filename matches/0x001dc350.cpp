#include "compat/ptr.h"
class CSPManager_1dc350 {
  public:
    char pad[0x608];
    int Find(char*);
    int target(char*);
};
int CSPManager_1dc350::target(char* s) {
    int result = -1;
    int idx = Find(s);
    if (idx >= 0 && s != 0 && *s != 0) {
        char* entry = (char*)this + 0x608 + idx * 0x28;
        short v = *(short*)(entry + 0x22);
        if ((*((unsigned char*)this + (v + 0x104e) * 0x14) & 1) != 0 && *(int*)(entry + 0x18) != 0)
            result = *(int*)(*(hulk_intptr*)(entry + 0x18) + 0x40);
        else
            result = (int)*(signed char*)(entry + 0x26);
    }
    return result;
}