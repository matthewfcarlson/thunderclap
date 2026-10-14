// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 8/8)
// FUN_0009d100 @ 0x0009d100
namespace pure3d { struct Animation { virtual void AddRef(); virtual void Release(); char pad[12]; float duration; float rate; }; }
namespace content { namespace LoadInventory { template<class T> struct DynamicCaster { virtual T* Cast(void*); }; } }
struct Key_9d100 { unsigned low, high; };
struct Inventory_9d100 { virtual void v0(); virtual void v1(); virtual void v2(); virtual pure3d::Animation* Find(content::LoadInventory::DynamicCaster<pure3d::Animation>*, unsigned, unsigned); };
struct Manager_9d100 { Inventory_9d100* FUN_00203d70(); };
struct Subsystem_9d100 { Manager_9d100* FUN_000862a0(); };
struct Global_9d100 { char pad[0x54]; Subsystem_9d100* subsystem; };
extern Global_9d100* DAT_004dd700;
struct Target_9d100 { char pad[0x1c]; int count; pure3d::Animation* animations[8]; float scales[8]; float offsets[8]; bool FUN_0009d100(Key_9d100* key, float scale, float offset); };
bool Target_9d100::FUN_0009d100(Key_9d100* key, float scale, float offset) { Inventory_9d100* inventory = DAT_004dd700->subsystem->FUN_000862a0()->FUN_00203d70(); content::LoadInventory::DynamicCaster<pure3d::Animation> caster; pure3d::Animation* anim = inventory->Find(&caster, key->low, key->high); if (!anim) return false; int index = count; if(index >= 8) return false; anim->AddRef(); if(animations[index]) animations[index]->Release(); animations[index] = anim; scales[count] = scale > 0.0f ? anim->duration / (scale * anim->rate) : 1.0f; offsets[count] = offset; ++count; return true; }