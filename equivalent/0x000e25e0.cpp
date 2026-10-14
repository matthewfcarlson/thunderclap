// STATUS: equivalent (tools/equiv.py level 3: 384 inputs, branch coverage 8/8)
// VScroll::vfunc_14 @ 0x000e25e0
struct Vec3 { float x,y,z; };
struct Transform { Vec3* FUN_000f6370(Vec3* out); char data[0x18]; };
struct Item { int id; float y; int unused; unsigned char enabled; char pad[3]; };
struct VScroll {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual Vec3* vfunc_14(Vec3* out,int id);
 char pad04[0x14]; Transform transform; float height; char pad34[0xc]; Item items[32]; int count;
};
Vec3* VScroll::vfunc_14(Vec3* out,int id) {
 int i; for(i=0;i<count;++i) if(items[i].id==id) break;
 if(i>=count) { out->z=0.0f; out->x=0.0f; out->y=0.0f; return out; }
 Item& item=items[i];
 if(!item.enabled) { out->z=-1.0f; out->x=0.0f; out->y=0.0f; return out; }
 Vec3 temp, temp2;
 Vec3* p=transform.FUN_000f6370(&temp);
 float y=height*0.5f+p->y-item.y;
 p=transform.FUN_000f6370(&temp);
 float z=p->z;
 p=transform.FUN_000f6370(&temp2);
 out->x=p->x; out->z=z; out->y=y; return out;
}