// STATUS: equivalent (tools/equiv.py level 3: 3032 inputs, branch coverage 12/12)
// FUN_00302d90 @ 0x00302d90
struct Shape_302d90 {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5();
 virtual int type();
 virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
 virtual bool apply(Shape_302d90*, float);
};
struct Item_302d90 { char pad[0x20]; Shape_302d90* shape; char pad2[0x2c]; unsigned char flag; };
struct Pair_302d90 { Item_302d90* first; Item_302d90* second; float FUN_002f8f10(int); };
float __cdecl FUN_003015c0(Shape_302d90*, Shape_302d90*);
float __cdecl FUN_00302480(Shape_302d90*, Shape_302d90*);
struct Handler_302d90 {
 char pad[0xc]; float value; float minimum; char pad2[0x28]; int setting;
 bool FUN_00302a00(Pair_302d90*,Shape_302d90*,Shape_302d90*);
 bool FUN_00302720(Pair_302d90*,float);
 bool target(Pair_302d90*);
};
bool Handler_302d90::target(Pair_302d90* pair) {
 float v=pair->FUN_002f8f10(setting);
 value = v > minimum ? v : minimum;
 Shape_302d90* first=pair->first->shape;
 Shape_302d90* second=pair->second->shape;
 bool result;
 if(first->type()==8) {
  if(second->type()==8) return false;
  result=FUN_00302720(pair,FUN_003015c0(first,second));
 } else if(second->type()==8) {
  result=FUN_00302720(pair,FUN_003015c0(second,first));
 } else if(pair->first->flag) {
  result=FUN_00302a00(pair,first,second);
 } else {
  result=FUN_00302720(pair,FUN_00302480(pair->second->shape,pair->first->shape));
 }
 if(result) result=first->apply(pair->second->shape,value);
 return result;
}