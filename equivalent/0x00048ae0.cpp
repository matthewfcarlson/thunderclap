// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 10/10)
// CCharacterSizeCondition::vfunc_7 @ 0x00048ae0
struct Character { char pad[0x14]; unsigned int size; };
struct Actor { char pad[0x11c]; Character* character; };
struct Context { Actor* FUN_00059a30(); };
struct Input { Context* FUN_000592a0(); };
class CCharacterSizeCondition {
public:
 char pad[0xc];
 int comparison;
 unsigned int size;
 unsigned int vfunc_7(Input* arg);
};
unsigned int CCharacterSizeCondition::vfunc_7(Input* arg) {
 Context* context = arg->FUN_000592a0();
 Actor* actor = context->FUN_00059a30();
 Character* character = actor->character;
 if (!character) return 0;
 unsigned int value = character->size;
 unsigned int result = 0;
 if (comparison == 0) result = value == size;
 else if (comparison == 1) result = value != size;
 return (value & 0xffffff00U) | result;
}