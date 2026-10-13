// STATUS: equivalent (tools/equiv.py level 3: 2034 inputs, branch coverage 18/18)
// FUN_001b4540 @ 0x001b4540
struct Data { char pad[0x74]; void* resource; };
struct Item { char pad[0x14c]; Data* owner; void FUN_00038c40(); };
struct List { char pad[0xc]; int count; Item* FUN_00024190(int index); };
struct Container { char pad[0x20]; List* list; };
struct Argument { char pad[0x1d9]; unsigned char flag; Data* FUN_001d72e0(); };
bool __cdecl FUN_002020a0(Data*);
struct Receiver { void FUN_002eecb0(void*); };
struct Target { char pad0[8]; Receiver* receiver; char pad1[0x4f4-0xc]; void* enabled; Container* container; bool FUN_001b4540(Argument* arg); };
bool Target::FUN_001b4540(Argument* arg) {
 if (!arg->FUN_001d72e0()) return false;
 void* resource = arg->FUN_001d72e0()->resource;
 if (!resource) return false;
 if (enabled && container && FUN_002020a0(arg->FUN_001d72e0())) {
  List* list = container->list;
  int count = list->count;
  for (int i=0; i<count; ++i) {
   Item* item = list->FUN_00024190(i);
   if (item) {
    Data* owner = item->owner;
    if (owner == arg->FUN_001d72e0()) item->FUN_00038c40();
   }
  }
 }
 receiver->FUN_002eecb0(resource);
 arg->flag = 1;
 return true;
}