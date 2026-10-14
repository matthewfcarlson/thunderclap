// STATUS: equivalent (tools/equiv.py level 3: 105 inputs, branch coverage 14/14)
// FUN_002d5fe0 @ 0x002d5fe0
struct Owner;
struct Item { char pad[0x2c]; volatile float current; volatile float limit; };
struct Pool { char pad[8]; volatile unsigned count; Item* volatile* volatile items; };
struct Updater { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void update(float, Owner*); virtual void special(float, Owner*); };
struct Owner {
 char pad0[0x84]; Pool* volatile pool; char pad88[4]; Updater* volatile updater; char pad90[0xbc]; volatile unsigned count; char pad150[12]; volatile unsigned char mode; char pad15d[0x6b]; Item* volatile* volatile items;
 void tick(float dt);
};
void Owner::tick(float dt) {
 Updater* handler = updater;
 if (!handler || !(dt > 0.0f)) return;
 if (mode == 1) { handler->special(dt, this); return; }
 handler->update(dt, this);
 Pool* destination = pool;
 unsigned kept = 0;
 for (unsigned i = 0; i < count; ++i) {
  Item* volatile* slot = &items[i];
  Item* item = *slot;
  Item* volatile nullableItem = item;
  if (item->current >= item->limit) {
   if (nullableItem) {
    unsigned n = destination->count;
    Item* volatile* buffer = destination->items;
    buffer[n] = item;
    n = destination->count;
    destination->count = n + 1;
    *slot = 0;
   }
  } else {
   *slot = 0; items[kept++] = item;
  }
 }
 count = kept;
}
