// STATUS: equivalent (tools/equiv.py level 3: 3028 inputs, branch coverage 13/14, incomplete)
// FUN_001ea700 @ 0x001ea700
namespace audio { class Clip; }
namespace content { class LoadInventory { public: template<class T> class DynamicCaster { public: virtual void cast(); }; }; }
struct Resource { virtual void slot0(); virtual void release(); char pad[0x1e]; unsigned short refs; };
struct Inventory { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual Resource* lookup(content::LoadInventory::DynamicCaster<audio::Clip>*, unsigned, unsigned); virtual void slot4(); virtual void remove(Resource*); };
struct System { char pad[0x518]; Inventory* inventory; };
extern System* DAT_004e3690;
extern float DAT_004e369c;
extern float DAT_004e36a0;
struct Key { unsigned first, second; };
struct Request { unsigned state; Key* key; unsigned size; unsigned unused; unsigned category; void FUN_001ea700(); };
void Request::FUN_001ea700() {
 if(state != 3) return;
 content::LoadInventory::DynamicCaster<audio::Clip> caster;
 Resource* resource = DAT_004e3690->inventory->lookup(&caster,key->first,key->second);
 if(resource) { --resource->refs; if(resource->refs == 0) { DAT_004e3690->inventory->remove(resource); resource->release(); } }
 double amount = (int)size;
 if((int)size < 0) amount += 4294967296.0f;
 if(category != 0) { DAT_004e369c = (float)(DAT_004e369c - amount); state=0; }
 else { DAT_004e36a0 = (float)(DAT_004e36a0 - amount); state=0; }
}
