#include "gen/global.h"

class Item {
  public:
    char pad[16];
    int size;
    int count;
    void** values;
};
class Manager {
  public:
    void Apply(void*);
};

void FEThings::vfunc_42(int __p0) { Item * p = (Item *)__p0;

    int n = p->count;
    for (int i = 0; i < n; ++i) {
        void* v = i < p->size ? p->values[i] : 0;
        (*(Manager * *)&this->f_2224)->Apply(v);
    }
}
