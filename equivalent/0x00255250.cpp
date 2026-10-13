// STATUS: equivalent (tools/equiv.py level 3: 574 inputs, branch coverage 17/18, incomplete)
// audio::SeqCommandLogicOr::vfunc_0 @ 0x00255250
struct RandomState { unsigned first, second; };
extern RandomState* DAT_004e5acc;
namespace audio {
struct SeqCommandLogicOr;
struct Context { void FUN_0025dbd0(SeqCommandLogicOr* command); };
struct Link { Link* next; };
struct Command {
 virtual void slot0();
 virtual void slot1();
 virtual void execute(Context* context);
 Link link;
};
struct CommandList { char pad[8]; unsigned count; Link* head; Link* tail; float fraction; };
struct SeqCommand { virtual void vfunc_0(Context*); virtual void vfunc_1(); unsigned unknown; CommandList* list; };
struct SeqCommandLogicOr : SeqCommand { virtual void vfunc_0(Context*); virtual void vfunc_1(); };
void SeqCommandLogicOr::vfunc_0(Context* context) {
 CommandList* l = list;
 if (l->count != 0) {
  unsigned range = (unsigned)(int)((double)(int)l->count * (double)l->fraction);
  if (!range) range = 1;
  RandomState* r = DAT_004e5acc;
  r->first = 36969u * (r->first & 65535u) + (r->first >> 16);
  r->second = 18000u * (r->second & 65535u) + (r->second >> 16);
  unsigned index = ((r->first << 16) + (r->second & 65535u)) % range;
  l = list;
  Link* selected = l->head;
  while (index--) selected = selected->next;
  Command* command = reinterpret_cast<Command*>(reinterpret_cast<char*>(selected) - 4);
  Link* prev = 0;
  Link* cur = l->head;
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