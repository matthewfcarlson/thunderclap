// STATUS: equivalent (tools/equiv.py level 3: 105 inputs, branch coverage 14/14)
// FUN_002d5fe0 @ 0x002d5fe0
struct SpriteParticleEmitter_2d5fe0;
struct Item_2d5fe0 { char pad[0x2c]; volatile float current; volatile float limit; };
struct Pool_2d5fe0 { char pad[8]; volatile unsigned count; Item_2d5fe0* volatile* volatile items; };
struct Updater_2d5fe0 { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void update(float, SpriteParticleEmitter_2d5fe0*); virtual void special(float, SpriteParticleEmitter_2d5fe0*); };
struct SpriteParticleEmitter_2d5fe0 {
 char pad0[0x84]; Pool_2d5fe0* volatile pool; char pad88[4]; Updater_2d5fe0* volatile updater; char pad90[0xbc]; volatile unsigned count; char pad150[12]; volatile unsigned char mode; char pad15d[0x6b]; Item_2d5fe0* volatile* volatile items;
 void tick(float dt);
};
void SpriteParticleEmitter_2d5fe0::tick(float dt) {
 Updater_2d5fe0* handler = updater;
 if (!handler || !(dt > 0.0f)) return;
 if (mode == 1) { handler->special(dt, this); return; }
 handler->update(dt, this);
 Pool_2d5fe0* destination = pool;
 unsigned kept = 0;
 for (unsigned i = 0; i < count; ++i) {
  Item_2d5fe0* volatile* slot = &items[i];
  Item_2d5fe0* item = *slot;
  Item_2d5fe0* volatile nullableItem = item;
  if (item->current >= item->limit) {
   if (nullableItem) {
    unsigned n = destination->count;
    Item_2d5fe0* volatile* buffer = destination->items;
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
