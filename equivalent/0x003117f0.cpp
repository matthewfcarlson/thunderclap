// STATUS: equivalent (tools/equiv.py level 3: 2993 inputs, branch coverage 32/32)
// FUN_003117f0 @ 0x003117f0
#include "compat/ptr.h"
typedef unsigned int UInt;
void __cdecl FUN_003117f0(UInt* first, UInt* middle, UInt* last)
{
    hulk_intptr distance = last - first;
    UInt a, b;
    if (distance > 40) {
        hulk_intptr step = (distance + 1) / 8;
        UInt* leftMedian = first + step;
        UInt* leftEnd = first + 2 * step;
        a = *leftMedian; b = *first;
        if (a < b) { *leftMedian = b; *first = a; }
        a = *leftEnd; b = *leftMedian;
        if (a < b) { *leftEnd = b; *leftMedian = a; }
        a = *leftMedian; b = *first;
        if (a < b) { *leftMedian = b; *first = a; }
        UInt* midStart = middle - step;
        UInt* midEnd = middle + step;
        a = *middle; b = *midStart;
        if (a < b) { *middle = b; *midStart = a; }
        a = *midEnd; b = *middle;
        if (a < b) { *midEnd = b; *middle = a; }
        a = *middle; b = *midStart;
        if (a < b) { *middle = b; *midStart = a; }
        UInt* rightMedian = last - step;
        UInt* rightStart = last - 2 * step;
        a = *rightMedian; b = *rightStart;
        if (a < b) { *rightMedian = b; *rightStart = a; }
        a = *last; b = *rightMedian;
        if (a < b) { *last = b; *rightMedian = a; }
        a = *rightMedian; b = *rightStart;
        if (a < b) { *rightMedian = b; *rightStart = a; }
        a = *middle; b = *leftMedian;
        if (a < b) { *middle = b; *leftMedian = a; }
        a = *rightMedian; b = *middle;
        if (a < b) { *rightMedian = b; *middle = a; }
        a = *middle; b = *leftMedian;
        if (a < b) { *middle = b; *leftMedian = a; }
    } else {
        a = *middle; b = *first;
        if (a < b) { *middle = b; *first = a; }
        a = *last; b = *middle;
        if (a < b) { *last = b; *middle = a; }
        a = *middle; b = *first;
        if (a < b) { *middle = b; *first = a; }
    }
}
