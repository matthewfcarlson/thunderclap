#include "gen/owners.h"
struct Range {
    unsigned int first;
    unsigned int last;
};
struct Object {
    void FUN_002f9ca0(unsigned int value);
};
void Object::FUN_002f9ca0(unsigned int value) {
    Range range;
    range.first = 0;
    range.last = 0xffffffff;
    ((owners::Buffer_2f9b60 *)this)->FUN_002f9b60(value, (Range *)(&range));
}