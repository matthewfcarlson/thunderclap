// STATUS: equivalent (tools/equiv.py level 3: 3007 inputs, branch coverage 12/12)
// FUN_00302d90 @ 0x00302d90
struct Shape {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5();
 virtual int type();
 virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
 virtual bool apply(Shape*, float);
};
struct Item { char pad[0x20]; Shape* shape; char pad2[0x2c]; unsigned char flag; };
struct Pair { Item* first; Item* second; float FUN_002f8f10(int); };
float __cdecl FUN_003015c0(Shape*, Shape*);
float __cdecl FUN_00302480(Shape*, Shape*);
struct Handler {
 char pad[0xc]; float value; float minimum; char pad2[0x28]; int setting;
 bool FUN_00302a00(Pair*,Shape*,Shape*);
 bool FUN_00302720(Pair*,float);
 bool target(Pair*);
};
bool Handler::target(Pair* pair) {
 float v=pair->FUN_002f8f10(setting);
 value = v > minimum ? v : minimum;
 Shape* first=pair->first->shape;
 Shape* second=pair->second->shape;
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