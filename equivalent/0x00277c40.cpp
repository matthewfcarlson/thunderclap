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
struct State_277c40 {
 Resource_277c40* resource;
 unsigned int field04, field08, field0c, field10, field14, field18, field1c, field20, field24, field28;
 void FUN_00277c40(Resource_277c40*, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
};
void State_277c40::FUN_00277c40(Resource_277c40* object, unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e, unsigned int f, unsigned int g) {
 object->slot0();
 field04 = a;
 field08 = 0;
 field10 = 0;
 field14 = 0;
 field1c = d;
 resource = object;
 field0c = b;
 field18 = c;
 field20 = object->slot16();
 field24 = e;
 field28 = f;
}
