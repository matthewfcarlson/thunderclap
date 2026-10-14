// STATUS: equivalent (tools/equiv.py level 3: 92 inputs, branch coverage 12/12)
// FUN_00222890 @ 0x00222890
struct Item_222890 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6();
 virtual unsigned int v7(); virtual unsigned int v8();
};
struct Entry_222890 {
 Item_222890* item;
 float value;
 bool negative;
 char pad[3];
 unsigned int first;
 unsigned int second;
 unsigned int arg3;
 float arg4;
 unsigned int arg5;
 unsigned int arg6;
 float arg7;
};
struct Owner_222890 {
 char pad[0x68];
 unsigned int count;
 Entry_222890 entries[16];
 bool dirty;
 bool FUN_002227d0(Item_222890*, float, unsigned int, float, unsigned int, unsigned int);
 bool FUN_00222890(Item_222890*, float, unsigned int, float, unsigned int, unsigned int, float);
};
bool Owner_222890::FUN_00222890(Item_222890* item, float value, unsigned int a3, float a4, unsigned int a5, unsigned int a6, float a7) {
 for (unsigned int i=0; i<count; ++i) {
  Entry_222890& entry=entries[i];
  if (entry.item != item) continue;
  entry.value=value;
  entry.negative=value < 0.0f;
  entry.first=item->v7();
  entry.second=item->v8();
  entry.arg3=a3;
  entry.arg4=a4 < 0.0f ? 0.0f : a4;
  entry.arg5=a5;
  entry.arg6=a6;
  if (a7 >= 0.0f) entry.arg7=a7;
  dirty=true;
  return true;
 }
 return FUN_002227d0(item,value,a3,a4,a5,a6);
}