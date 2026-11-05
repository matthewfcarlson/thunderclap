#include "compat/ptr.h"
struct ScriptHandler_1d27b0 {
    char pad[8];
    int value;
    hulk_intptr Fn(hulk_intptr x);
    int Other(int, int);
};
hulk_intptr ScriptHandler_1d27b0::Fn(hulk_intptr x) {
    return Other(x, value);
}