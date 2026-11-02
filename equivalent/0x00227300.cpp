// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00227300 @ 0x00227300
struct Point_227300 { unsigned int x; union { float y; unsigned int yBits; }; unsigned int z; };
extern "C" void __cdecl FUN_00227300(void * a_, void * b_, void * c)
{
    Point_227300 * a = (Point_227300 *)a_;
    Point_227300 * b = (Point_227300 *)b_;
    if (b->y > a->y) {
        unsigned int x = b->x, y = b->yBits, z = b->z;
        b->x = a->x; b->yBits = a->yBits; b->z = a->z;
        a->x = x; a->yBits = y; a->z = z;
    }
    if (((Point_227300 *)c)->y > b->y) {
        unsigned int x = ((Point_227300 *)c)->x, y = ((Point_227300 *)c)->yBits, z = ((Point_227300 *)c)->z;
        ((Point_227300 *)c)->x = b->x; ((Point_227300 *)c)->yBits = b->yBits; ((Point_227300 *)c)->z = b->z;
        b->x = x; b->yBits = y; b->z = z;
    }
    if (b->y > a->y) {
        unsigned int x = b->x, y = b->yBits, z = b->z;
        b->x = a->x; b->yBits = a->yBits; b->z = a->z;
        a->x = x; a->yBits = y; a->z = z;
    }
}
