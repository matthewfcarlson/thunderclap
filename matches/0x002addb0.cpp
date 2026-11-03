#include "gen/owners.h"
unsigned int owners::Transform_2addb0::FUN_002addb0(unsigned int x) {
    return (((x & 0xff) >> r0) << s2) | (((x & 0xff0000) >> r1) << s0) | (((x & 0xff000000) >> r3) << s1) |
           (((x & 0xff00) >> r2) << s3);
}