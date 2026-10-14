// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_000f81b0 @ 0x000f81b0
struct Slot {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
 virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
 virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
 virtual void v12(); virtual void v13();
 virtual void getValue(unsigned* value);
 virtual void setValue(unsigned value);
};
struct Owner {
 char pad[0x24];
 Slot* slots[61];
 unsigned state;
 void FUN_000f7d60(unsigned a, unsigned index, unsigned x, unsigned y, unsigned z, unsigned b);
};
struct Row { unsigned x,y,z,value; };
struct Context {
 Owner* owner;
 unsigned unused;
 Row rows[8];
 unsigned current;
 unsigned state;
 unsigned target(unsigned a, unsigned index, unsigned b);
};
unsigned Context::target(unsigned a, unsigned index, unsigned b) {
 unsigned slotIndex = index;
 Slot* slot = owner->slots[slotIndex];
 if(slot) slot->getValue(&index); else index = 0xffffffff;
 unsigned value = rows[current].value;
 slot = owner->slots[slotIndex];
 if(slot) slot->setValue(value);
 unsigned savedState = owner->state;
 owner->state = state;
 owner->FUN_000f7d60(a, slotIndex, rows[current].x, rows[current].y, rows[current].z, b);
 slot = owner->slots[slotIndex];
 if(slot) slot->setValue(index);
 owner->state = savedState;
 return savedState;
}