#include "compat/ptr.h"
int __cdecl GetVal(int elem);

class Other_fdd30 {
  public:
    int Check(int v);
};

class Container_fdd30 {
  public:
    int FindSomething(hulk_intptr arg);
    char pad[8];
    int mCount;
    int mArray[1];
};

int Container_fdd30::FindSomething(hulk_intptr arg) {
    Other_fdd30* o = (Other_fdd30*)arg;
    int e;
    int i = 0;
    if (mCount > 0) {
        int* p = mArray;
        do {
            e = *p;
            if (o->Check(GetVal(e))) {
                return e;
            }
            ++i;
            ++p;
        } while (i < mCount);
    }
    return 0;
}
