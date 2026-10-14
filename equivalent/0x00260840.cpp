// STATUS: equivalent (tools/equiv.py level 3: 1252 inputs, branch coverage 16/16)
// audio::SeqEventContainer::vfunc_1 @ 0x00260840
struct Writer { char pad[0x24]; unsigned depth; };
extern bool __cdecl FUN_00246f50(Writer*, const char*, ...);
struct NameService { const char* FUN_0023fb00(); };
extern NameService* __cdecl FUN_0024c710();
namespace audio {
struct EventLink { EventLink* next; };
struct SeqEvent {
 virtual void vfunc_0();
 virtual bool vfunc_1(Writer**);
 virtual void FUN_00344f51();
 virtual void slot3();
 EventLink link;
};
struct SeqEventContainer : SeqEvent {
 char padding[4];
 EventLink* children;
 virtual bool vfunc_1(Writer**);
};
bool SeqEventContainer::vfunc_1(Writer** output) {
 if (!FUN_00246f50(*output,"mChildren\n[\n")) return false;
 ++(*output)->depth;
 SeqEvent* child = children ? reinterpret_cast<SeqEvent*>(reinterpret_cast<char*>(children)-4) : 0;
 while (child) {
  child->slot3();
  Writer* writer = *output;
  const char* name = FUN_0024c710()->FUN_0023fb00();
  if (!FUN_00246f50(writer,"%s\n",name)) return false;
  if (!child->vfunc_1(output)) return false;
  if (!FUN_00246f50(*output,"\n")) return false;
  EventLink* next = child->link.next;
  child = next ? reinterpret_cast<SeqEvent*>(reinterpret_cast<char*>(next)-4) : 0;
 }
 --(*output)->depth;
 return FUN_00246f50(*output,"]\n") != false;
}
}