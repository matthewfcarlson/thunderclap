// STATUS: equivalent (tools/equiv.py level 3: 105 inputs, branch coverage 14/14)
// FUN_002d5fe0 @ 0x002d5fe0
#include "gen/pure3d.h"

struct Item_2d5fe0 { char pad[0x2c]; volatile float current; volatile float limit; };
struct Pool_2d5fe0 { char pad[8]; volatile unsigned count; Item_2d5fe0* volatile* volatile items; };
struct Updater_2d5fe0 { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void update(float, pure3d::SpriteParticleEmitter*); virtual void special(float, pure3d::SpriteParticleEmitter*); };

void pure3d::SpriteParticleEmitter::FUN_002d5fe0(float dt) {
 Updater_2d5fe0* handler = (*(Updater_2d5fe0 *volatile *)&this->f_8c);
 if (!handler || !(dt > 0.0f)) return;
 if ((*(volatile unsigned char *)&this->f_15c) == 1) { handler->special(dt, this); return; }
 handler->update(dt, this);
 Pool_2d5fe0* destination = (*(Pool_2d5fe0 *volatile *)&this->f_84);
 unsigned kept = 0;
 for (unsigned i = 0; i < (*(volatile unsigned int *)&this->f_14c); ++i) {
  Item_2d5fe0* volatile* slot = &(*(Item_2d5fe0 *volatile *volatile *)&this->f_1c8)[i];
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
   *slot = 0; (*(Item_2d5fe0 *volatile *volatile *)&this->f_1c8)[kept++] = item;
  }
 }
 (*(volatile unsigned int *)&this->f_14c) = kept;
}
