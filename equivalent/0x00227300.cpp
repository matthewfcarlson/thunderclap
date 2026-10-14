// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00227300 @ 0x00227300
struct Point { unsigned int x; union { float y; unsigned int yBits; }; unsigned int z; };
void __cdecl FUN_00227300(Point* a, Point* b, Point* c)
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
