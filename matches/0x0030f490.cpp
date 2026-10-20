#include "compat/ptr.h"
struct Info {
    char pad[16];
    int count;
};
struct Elem {
    char bytes[192];
};
class Table {
    char pad[8];
    Info* info;
    Elem* entries;

  public:
    Elem* Get(int index);
};
Elem* Table::Get(int index) {
    if (index >= 0) {
        hulk_intptr count = (hulk_intptr)info;
        if (count)
            count = ((Info*)count)->count;
        if (index < count)
            return &entries[index];
    }
    return 0;
}