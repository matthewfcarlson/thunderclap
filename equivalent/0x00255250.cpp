// STATUS: equivalent (tools/equiv.py level 3: 574 inputs, branch coverage 17/18, incomplete)
// audio::SeqCommandLogicOr::vfunc_0 @ 0x00255250
#include "decls/data/game/unknown.h"

struct RandomState_255250 { unsigned first, second; };
namespace audio {
struct SeqCommandLogicOr;
struct Context { void FUN_0025dbd0(SeqCommandLogicOr* command); };
struct Link_255250 { Link_255250* next; };
struct Command_255250 {
 virtual void slot0();
 virtual void slot1();
 virtual void execute(Context* context);
 Link_255250 link;
};
struct CommandList_255250 { char pad[8]; unsigned count; Link_255250* head; Link_255250* tail; float fraction; };
struct SeqCommand { virtual void vfunc_0(Context*); virtual void vfunc_1(); unsigned unknown; CommandList_255250* list; };
struct SeqCommandLogicOr : SeqCommand { virtual void vfunc_0(Context*); virtual void vfunc_1(); };
void SeqCommandLogicOr::vfunc_0(Context* context) {
 CommandList_255250* l = list;
 if (l->count != 0) {
  unsigned range = (unsigned)(int)((double)(int)l->count * (double)l->fraction);
  if (!range) range = 1;
  RandomState_255250* r = (*(RandomState_255250**)&DAT_004e5acc);
  r->first = 36969u * (r->first & 65535u) + (r->first >> 16);
  r->second = 18000u * (r->second & 65535u) + (r->second >> 16);
  unsigned index = ((r->first << 16) + (r->second & 65535u)) % range;
  l = list;
  Link_255250* selected = l->head;
  while (index--) selected = selected->next;
  Command_255250* command = reinterpret_cast<Command_255250*>(reinterpret_cast<char*>(selected) - 4);
  Link_255250* prev = 0;
  Link_255250* cur = l->head;
  while (cur != selected) { prev = cur; cur = cur->next; }
  if (prev) prev->next = selected->next; else l->head = selected->next;
  if (!selected->next) l->tail = prev;
  --l->count;
  l = list;
  selected->next = 0;
  if (l->tail) l->tail->next = selected; else l->head = selected;
  l->tail = selected;
  ++l->count;
  context->FUN_0025dbd0(this);
  command->execute(context);
 } else context->FUN_0025dbd0(this);
}
}