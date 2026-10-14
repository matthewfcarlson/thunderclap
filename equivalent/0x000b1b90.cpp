// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// FUN_000b1b90 @ 0x000b1b90
struct Item_b1b90 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual float value(int);
};
struct Collection_b1b90 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual int count(const char*); virtual Item_b1b90* get(const char*,int);
};
struct Result_b1b90 { float value; int state; Item_b1b90* item; };
struct Object {
 char pad0[0x10]; Collection_b1b90* collection; char pad1[0x40]; int state; char pad2[0x438]; float low; float high;
 void FUN_000b1b90(Result_b1b90* result);
};
void Object::FUN_000b1b90(Result_b1b90* result) {
 if(state==2 || !collection) return;
 result->value=0.0f;
 int n=collection->count("Button");
 Item_b1b90* selected=0;
 float ratio=0.0f;
 for(int i=0;i<n;++i) {
  Item_b1b90* item=collection->get("Button",i);
  if(!item) ratio=0.0f;
  else {
   float value=item->value(0);
   if(value<low) ratio=0.0f;
   else if(value>high) ratio=1.0f;
   else ratio=(value-low)/(high-low);
  }
  union { float f; unsigned int u; } magnitude;
  magnitude.f=ratio; magnitude.u &= 0x7fffffff;
  if(!(magnitude.f<=1e-05f)) { selected=item; break; }
 }
 result->value=ratio;
 result->item=selected;
 result->state=state;
}
