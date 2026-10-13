// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 17/20, incomplete)
// FUN_0029faf0 @ 0x0029faf0
struct Vec { float x,y,z; };
struct Pool { void* FUN_0029f280(); };
struct Item { char pad0[0x18]; unsigned int value18; char pad1[0x18]; unsigned int color; void FUN_0029e7f0(void*,void*,unsigned int); };
struct Object {
 char pad0[0x10]; unsigned int color; char pad1[4]; unsigned int value18; char pad2[8]; unsigned int value24; char pad3[0x1c]; Pool* pool;
 bool FUN_0029e5c0(void*,Item*);
 void FUN_0029ce40(Vec*,void*);
 void FUN_0029df90(void*,Vec*,void*);
 void target(void* arg, Item* item);
};
void Object::target(void* arg, Item* item) {
 if (FUN_0029e5c0(arg,item)) { color=item->color; return; }
 void* handle=pool->FUN_0029f280();
 Vec v;
 FUN_0029ce40(&v,arg);
 FUN_0029df90(handle,&v,arg);
 int b=(int)v.z;
 int g=(int)v.y;
 int r=(int)v.x;
 if(b<0)b=0; else if(b>255)b=255;
 if(g<0)g=0; else if(g>255)g=255;
 if(r<0)r=0; else if(r>255)r=255;
 color=0xff000000u | ((unsigned int)r<<16) | ((unsigned int)g<<8) | b;
 item->value18=value18;
 item->FUN_0029e7f0(handle,arg,value24);
 item->color=color;
}