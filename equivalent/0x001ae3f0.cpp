// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_001ae3f0 @ 0x001ae3f0
#include "compat/ptr.h"
struct Record { int value; char rest[16]; };
struct Query { char padding[12]; int identity; int value; };
struct Range { char padding[4]; Record* begin; Record* end; char padding2[8]; int identity; };
unsigned int __cdecl FUN_001ae3f0(Query* query, Range* range)
{
    hulk_uintptr result = (unsigned int)range->identity;
    if (range->identity == query->identity) {
        Record* end = range->end;
        result = (hulk_uintptr)end;
        if (range->begin != end) {
            Record* last = end - 1;
            if (query->value == last->value)
                return (result & 0xffffff00U) | 1;
            hulk_intptr count = end - range->begin;
            result = (unsigned int)count;
            if ((unsigned int)count >= 2) {
                range->end = last;
                if (query->value == (last - 1)->value)
                    return (result & 0xffffff00U) | 1;
            }
        }
    }
    return result & 0xffffff00U;
}