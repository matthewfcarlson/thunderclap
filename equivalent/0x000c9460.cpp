// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_000c9460 @ 0x000c9460
struct Surface {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4();
 virtual int width(); virtual int height();
};
struct Holder { char pad[16]; Surface* surface; };
struct Point { float x,y; };
struct Mapper {
 char pad0[16]; Holder* holder; char pad1[44]; float sx,sy,ox,oy;
 Point* FUN_000c9460(Point* output, float x, float unused, float y);
};
Point* Mapper::FUN_000c9460(Point* output, float x, float unused, float y) {
 int w = holder->surface->width();
 float u = (x * sx + ox) / w;
 int h = holder->surface->height();
 float v = 1.0f - (y * sy + oy) / h;
 if (!(u >= 0.0f && u <= 1.0f)) u = u > 1.0f ? 1.0f : 0.0f;
 if (!(v >= 0.0f && v <= 1.0f)) v = v > 1.0f ? 1.0f : 0.0f;
 output->x=u; output->y=v;
 return output;
}