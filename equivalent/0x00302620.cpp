// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00302620 @ 0x00302620
extern "C" double __cdecl sqrt(double);
struct Vec3 { float x,y,z; };
struct Shape {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual Vec3* position();
 char pad04[0x30]; float radius; char pad38[0xc]; Vec3 normal; float extent; float thickness; unsigned char flag;
};
float __cdecl FUN_00302620(Shape* a, Shape* b) {
 float limit = a->flag ? a->extent : a->thickness + a->extent;
 Vec3* pa=a->position(); Vec3* pb=b->position();
 float dx=pb->x-pa->x, dy=pb->y-pa->y;
 double dzWide=(double)pb->z-pa->z;
 float dz=(float)dzWide;
 double dot=dzWide*a->normal.z+(double)dy*a->normal.y+(double)dx*a->normal.x;
 double x=dx-dot*a->normal.x, y=dy-dot*a->normal.y, z=dz-dot*a->normal.z;
 union { float f; unsigned int u; } length, distance;
 length.f=(float)sqrt(z*z+x*x+y*y); length.u &= 0x7fffffff;
 float edge=(float)((double)length.f-((double)a->thickness+b->radius));
 distance.f=(float)dot; distance.u &= 0x7fffffff;
 double face=(double)distance.f-((double)limit+b->radius);
 return face<edge ? edge : (float)face;
}