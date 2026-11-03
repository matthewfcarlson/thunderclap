#include "decls/data/engine/unknown.h"
// data: g_first_33eb70 = DAT_005660d8, g_second_33eb70 = DAT_005660dc

typedef unsigned int u32_33eb70;
struct Setter_33eb70 {
    void Set(u32_33eb70 first, u32_33eb70 second);
};
void Setter_33eb70::Set(u32_33eb70 first, u32_33eb70 second) {
    (*(u32_33eb70*)&DAT_005660d8) = first;
    (*(u32_33eb70*)&DAT_005660dc) = second;
}