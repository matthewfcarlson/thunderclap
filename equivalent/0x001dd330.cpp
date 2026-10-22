// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_001dd330 @ 0x001dd330
struct Source_1dd330 { char pad[0x30]; unsigned int x,y,z; };
struct Temp_1dd330 { unsigned int data[4]; void FUN_0022b370(Source_1dd330*); };
struct Link_1dd330 { unsigned int data[2]; void FUN_0027af70(void*); };
struct State_1dd330 { char pad[6]; unsigned short id; char rest[10]; unsigned short recordIndex; char pad2[2]; unsigned char active,inverted; void FUN_001db780(Temp_1dd330*); };
struct Item_1dd330 { Link_1dd330 first,second; State_1dd330 state; void FUN_001dbba0(); };
struct Record_1dd330 { unsigned int x,y,z; float distance; union { unsigned short flags; struct { unsigned char low,high; } bytes; }; unsigned short itemIndex; };
struct CSPManager_1dd330 { char pad[0x608]; Item_1dd330 items[2048]; Record_1dd330 records[2048]; int nextItem; char gap[8]; int count; void FUN_001dbe60(); void FUN_001dcd30(int); int target(void*,void*,Source_1dd330*,unsigned char,unsigned char,unsigned char,unsigned char); };
int CSPManager_1dd330::target(void* a,void* b,Source_1dd330* source,unsigned char mark,unsigned char notify,unsigned char flag,unsigned char enabled) {
 if(count>=2048) return -1;
 Item_1dd330* item=&items[nextItem]; Record_1dd330* record=&records[count];
 item->FUN_001dbba0();
 record->itemIndex=0xffff;
 record->x=0; record->y=0; record->z=0;
 record->distance=3.402823466e+38f; record->flags=0;
 item->state.recordIndex=(unsigned short)count;
 record->itemIndex=(unsigned short)nextItem;
 Temp_1dd330 temp; temp.FUN_0022b370(source);
 item->first.FUN_0027af70(a);
 item->state.FUN_001db780(&temp);
 item->state.active=0;
 item->second.FUN_0027af70(b);
 item->state.id=0xffff; item->state.inverted=(enabled==0);
 record->x=source->x; record->y=source->y; record->z=source->z;
 if(flag) record->bytes.low|=0x20; else record->bytes.low&=0xdf;
 int result=nextItem; ++count;
 FUN_001dbe60();
 if(mark) record->bytes.low|=2;
 if(notify) FUN_001dcd30(result);
 return result;
}