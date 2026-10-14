// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_001bc530 @ 0x001bc530
struct Vec2_1bc530 {
    float x, y;
};

struct Rect_1bc530 {
    float minX;
    float maxY;
    float maxX;
    float minY;
};

struct Mapper_1bc530 {
    void FUN_00292cc0(int arg, Vec2_1bc530* out);
};

struct Inner_1bc530 {
    Mapper_1bc530* FUN_001c19a0();
};

struct Holder_1bc530 {
    Inner_1bc530* inner;
};

Holder_1bc530* FUN_001c3d90();

// Grows the rect (passed in esi) to include the point mapped from arg.
// equiv-conv: FUN_001bc530 esi stack
void FUN_001bc530(Rect_1bc530* rect, int arg)
{
    Vec2_1bc530 p;
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
