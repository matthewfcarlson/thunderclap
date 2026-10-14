// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_001bc530 @ 0x001bc530
struct Vec2 {
    float x, y;
};

struct Rect {
    float minX;
    float maxY;
    float maxX;
    float minY;
};

struct Mapper {
    void FUN_00292cc0(int arg, Vec2* out);
};

struct Inner {
    Mapper* FUN_001c19a0();
};

struct Holder {
    Inner* inner;
};

Holder* FUN_001c3d90();

// Grows the rect (passed in esi) to include the point mapped from arg.
// equiv-conv: FUN_001bc530 esi stack
void FUN_001bc530(Rect* rect, int arg)
{
    Vec2 p;
    float spare;
    FUN_001c3d90()->inner->FUN_001c19a0()->FUN_00292cc0(arg, &p);
    if (p.x < rect->minX)
        rect->minX = p.x;
    if (p.y > rect->maxY)
        rect->maxY = p.y;
    if (p.x > rect->maxX)
        rect->maxX = p.x;
    if (p.y < rect->minY)
        rect->minY = p.y;
}
