// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00229560 @ 0x00229560
struct Point_229560 { unsigned int x; union { float y; unsigned int yBits; }; unsigned int z; };
extern "C" void __cdecl FUN_00229560(void * a_, void * b_, void * c)
{
    Point_229560 * a = (Point_229560 *)a_;
    Point_229560 * b = (Point_229560 *)b_;
    if (b->y > a->y) {
        unsigned int x = b->x, y = b->yBits, z = b->z;
        b->x = a->x; b->yBits = a->yBits; b->z = a->z;
        a->x = x; a->yBits = y; a->z = z;
    }
    if (((Point_229560 *)c)->y > b->y) {
        unsigned int x = ((Point_229560 *)c)->x, y = ((Point_229560 *)c)->yBits, z = ((Point_229560 *)c)->z;
        ((Point_229560 *)c)->x = b->x; ((Point_229560 *)c)->yBits = b->yBits; ((Point_229560 *)c)->z = b->z;
        b->x = x; b->yBits = y; b->z = z;
    }
    if (b->y > a->y) {
        unsigned int x = b->x, y = b->yBits, z = b->z;
        b->x = a->x; b->yBits = a->yBits; b->z = a->z;
        a->x = x; a->yBits = y; a->z = z;
    }
}
