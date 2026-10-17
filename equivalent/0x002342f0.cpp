// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// fight::Param::vfunc_3 @ 0x002342f0
typedef unsigned __int64 uint64;
struct Source {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
 virtual void slot12(); virtual bool slot13(); virtual uint64 slot14(); virtual void slot15();
 virtual void slot16(uint64 value); virtual void slot17();
};
namespace fight {
struct Param {
 virtual void FUN_00344f51();
 virtual void vfunc_1();
 virtual void vfunc_2();
 virtual bool vfunc_3(unsigned int low, unsigned int high, unsigned int value, Source* source);
 virtual void vfunc_4(unsigned int value, Source* source);
 virtual void vfunc_5();
};
bool Param::vfunc_3(unsigned int low, unsigned int high, unsigned int value, Source* source) {
 if (!source->slot13()) return false;
 uint64 id = source->slot14();
 if (id != ((uint64)high << 32 | low)) return false;
 source->slot16(id);
 vfunc_4(value, source);
 source->slot17();
 return true;
}
}