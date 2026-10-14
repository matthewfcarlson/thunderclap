// STATUS: equivalent (tools/equiv.py level 3: 2034 inputs, branch coverage 18/18)
// FUN_001b4540 @ 0x001b4540
struct Data_1b4540 { char pad[0x74]; void* resource; };
struct Item_1b4540 { char pad[0x14c]; Data_1b4540* owner; void FUN_00038c40(); };
struct List_1b4540 { char pad[0xc]; int count; Item_1b4540* FUN_00024190(int index); };
struct Container_1b4540 { char pad[0x20]; List_1b4540* list; };
struct Argument_1b4540 { char pad[0x1d9]; unsigned char flag; Data_1b4540* FUN_001d72e0(); };
bool __cdecl FUN_002020a0(Data_1b4540*);
struct Receiver_1b4540 { void FUN_002eecb0(void*); };
struct Target_1b4540 { char pad0[8]; Receiver_1b4540* receiver; char pad1[0x4f4-0xc]; void* enabled; Container_1b4540* container; bool FUN_001b4540(Argument_1b4540* arg); };
bool Target_1b4540::FUN_001b4540(Argument_1b4540* arg) {
 if (!arg->FUN_001d72e0()) return false;
 void* resource = arg->FUN_001d72e0()->resource;
 if (!resource) return false;
 if (enabled && container && FUN_002020a0(arg->FUN_001d72e0())) {
  List_1b4540* list = container->list;
  int count = list->count;
  for (int i=0; i<count; ++i) {
   Item_1b4540* item = list->FUN_00024190(i);
   if (item) {
    Data_1b4540* owner = item->owner;
    if (owner == arg->FUN_001d72e0()) item->FUN_00038c40();
   }
  }
 }
 receiver->FUN_002eecb0(resource);
 arg->flag = 1;
 return true;
}