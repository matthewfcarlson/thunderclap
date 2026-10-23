// STATUS: equivalent (tools/equiv.py level 3: 18813 inputs, branch coverage 18/18)
// audio::SeqCommandLogicOr::vfunc_0 @ 0x00255250
#include "gen/audio.h"

#include "decls/data/game/unknown.h"

struct RandomState_255250 { unsigned first, second; };
namespace audio {

struct Context_255250 { void FUN_0025dbd0(audio::SeqCommandLogicOr* command); };
struct Link_255250 { Link_255250* next; };
struct Command_255250 {
 virtual void slot0();
 virtual void slot1();
 virtual void execute(Context_255250* context);
 Link_255250 link;
};
struct CommandList_255250 { char pad[8]; unsigned count; Link_255250* head; Link_255250* tail; float fraction; };
struct SeqCommand_255250 { virtual void vfunc_0(Context_255250*); virtual void vfunc_1(); unsigned unknown; CommandList_255250* list; };

}
void audio::SeqCommandLogicOr::vfunc_0(int __p0) { Context_255250 * context = (Context_255250 *)__p0;

 CommandList_255250* l = (*(CommandList_255250 * *)&this->f_08);
 if (l->count != 0) {
  unsigned range = (unsigned)(int)(__int64)((double)(int)(__int64)l->count * (double)l->fraction);
  if (!range) range = 1;
  RandomState_255250* r = (*(RandomState_255250**)&DAT_004e5acc);
  r->first = 36969u * (r->first & 65535u) + (r->first >> 16);
  r->second = 18000u * (r->second & 65535u) + (r->second >> 16);
  unsigned index = ((r->first << 16) + (r->second & 65535u)) % range;
  l = (*(CommandList_255250 * *)&this->f_08);
  Link_255250* selected = l->head;
  while (index--) selected = selected->next;
  Command_255250* command = reinterpret_cast<Command_255250*>(reinterpret_cast<char*>(selected) - 4);
  Link_255250* prev = 0;
  Link_255250* cur = l->head;
  while (cur != selected) { prev = cur; cur = cur->next; }
  if (prev) prev->next = selected->next; else l->head = selected->next;
  if (!selected->next) l->tail = prev;
  --l->count;
  l = (*(CommandList_255250 * *)&this->f_08);
  selected->next = 0;
  if (l->tail) l->tail->next = selected; else l->head = selected;
  l->tail = selected;
  ++l->count;
  context->FUN_0025dbd0(this);
  command->execute(context);
 } else context->FUN_0025dbd0(this);
}
