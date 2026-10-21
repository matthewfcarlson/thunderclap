#include "compat/ptr.h"
struct Item_ad2b0 {
    char pad[0x4a0];
    float value;
};
struct Container_ad2b0 {
    char pad[0x10];
    int count;
    Item_ad2b0** items;
    hulk_freg target();
};
hulk_freg Container_ad2b0::target() {
    float result = 3.402823466e+38f;
    for (int i = 0; i < count; ++i) {
        float value = items[i]->value;
        if (value < result)
            result = value;
    }
    return result;
}
