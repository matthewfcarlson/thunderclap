// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// FUN_001d71e0 @ 0x001d71e0
struct Value { unsigned int value; char rest[28]; void FUN_00067e60(void*); void FUN_000679c0(); };
struct Manager { void* FUN_00067ad0(unsigned int); void FUN_00067c30(unsigned int, Value*); };
struct Services { char pad[8]; Manager* manager; };
struct Global { char pad[32]; Services* services; };
extern Global* DAT_004dd700;
struct Payload { char pad[16]; unsigned int* value; };
struct Reference { virtual void addRef(); virtual void release(); unsigned int reserved; Payload* payload; unsigned int type; };
struct Object { char pad[0x118]; Reference* reference; char pad2[0x1cc-0x11c]; unsigned int key; void FUN_001d71e0(Reference*); };
void Object::FUN_001d71e0(Reference* next) {
 if(reference == next) return;
 if(next) next->addRef();
 if(reference) reference->release();
 reference=next;
 if(!key) return;
 Manager* manager=DAT_004dd700->services->manager;
 void* found=manager->FUN_00067ad0(key);
 if(!found) return;
 Value value; value.FUN_00067e60(found);
 if(reference && reference->type==1 && reference->payload) value.value=*reference->payload->value;
 else value.value=0;
 manager->FUN_00067c30(key,&value);
 value.FUN_000679c0();
}
