#include "compat/ptr.h"
struct Item {
    hulk_intptr a, b;
    Item(void*) throw();
    void Assign(const Item*) throw();
    ~Item() throw();
};
class Owner {
    char pad[0x35a0];
    Item items[20];
    int count;

  public:
    void Add(void*);
};
void Owner::Add(void* p) {
    Item t(p);
    items[count++].Assign(&t);
}