// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_00277c40 @ 0x00277c40
struct Resource_277c40 {
 virtual void slot0();
 virtual void slot1();
 virtual void slot2();
 virtual void slot3();
 virtual void slot4();
 virtual void slot5();
 virtual void slot6();
 virtual void slot7();
 virtual void slot8();
 virtual void slot9();
 virtual void slot10();
 virtual void slot11();
 virtual void slot12();
 virtual void slot13();
 virtual void slot14();
 virtual void slot15();
 virtual unsigned int slot16();
};
#include "decls/data/records.h"
// core::File's view of its cement library entry (records.h CoreFileView): the library (a reference) and the entry's
// offsets; words[7] is the library's slot 16
struct State_277c40 : CoreFileView {
 void FUN_00277c40(Resource_277c40*, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
};
void State_277c40::FUN_00277c40(Resource_277c40* object, unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e, unsigned int f, unsigned int g) {
 object->slot0();
 words[0] = a;
 words[1] = 0;
 words[3] = 0;
 words[4] = 0;
 words[6] = d;
 resource = object;
 words[2] = b;
 words[5] = c;
 words[7] = object->slot16();
 words[8] = e;
 words[9] = f;
}
