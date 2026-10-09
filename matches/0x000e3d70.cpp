struct Sub { void fn(int); };
class Obj {
public:
 char pad0[0xa4]; int value;
 char pad1[0x495c-0xa8]; int width; int height;
 char tail[1];
 void update(int x,int y,int z);
};
void Obj::update(int x,int y,int z) {
 if (x < width && y < height) {
  Sub *p=(Sub*)((char*)this+0x15c+(y+x*8)*0x24);
  p->fn(z);
  *(int*)p=value;
 }
}