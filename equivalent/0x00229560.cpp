// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00229560 @ 0x00229560
struct Point_229560 { unsigned int x; union { float y; unsigned int yBits; }; unsigned int z; };
void __cdecl FUN_00229560(Point_229560* a, Point_229560* b, Point_229560* c)
{
    if (b->y > a->y) {
        unsigned int x = b->x, y = b->yBits, z = b->z;
        b->x = a->x; b->yBits = a->yBits; b->z = a->z;
        a->x = x; a->yBits = y; a->z = z;
    }
    if (c->y > b->y) {
        unsigned int x = c->x, y = c->yBits, z = c->z;
        c->x = b->x; c->yBits = b->yBits; c->z = b->z;
        b->x = x; b->yBits = y; b->z = z;
    }
    if (b->y > a->y) {
        unsigned int x = b->x, y = b->yBits, z = b->z;
        b->x = a->x; b->yBits = a->yBits; b->z = a->z;
        a->x = x; a->yBits = y; a->z = z;
    }
}
