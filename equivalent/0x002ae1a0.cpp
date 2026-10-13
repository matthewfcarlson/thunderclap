// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// FUN_002ae1a0 @ 0x002ae1a0
struct Surface {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void setPalette(int count, void* palette);
};
struct Resource {
 virtual void slot0(); virtual void release();
 char pad[12]; Surface* surface;
 Resource* FUN_002c1c30();
 void FUN_002c1c70(int width,int height,int depth,int a,int b,int palette,int c);
};
struct Manager { virtual void slot0(); virtual void slot1(); virtual int slot2(); };
extern Manager* DAT_0052c2a0;
extern void* __cdecl FUN_00263ea0(int);
struct Object {
 int field0; Resource* resource; char pad[24]; int field20; int field24; int field28; int field2c; int depth;
 int run(int width,int height,int requestedDepth,int unused,void* palette);
};
int Object::run(int width,int height,int requestedDepth,int unused,void* palette) {
 if(resource) resource->release();
 Resource* p=(Resource*)FUN_00263ea0(24);
 if(p) p=p->FUN_002c1c30();
 resource=p;
 if(depth==16) resource->FUN_002c1c70(width,height,16,field20,field24,0,field2c);
 else if(depth>8 || requestedDepth>8) resource->FUN_002c1c70(width,height,32,field20,field24,0,field2c);
 else if(requestedDepth==8) { resource->FUN_002c1c70(width,height,8,field20,field24,1,field2c); resource->surface->setPalette(256,palette); }
 else if(requestedDepth==4) { resource->FUN_002c1c70(width,height,4,field20,field24,1,field2c); resource->surface->setPalette(16,palette); }
 if(resource->surface) return DAT_0052c2a0->slot2();
 return 0;
}