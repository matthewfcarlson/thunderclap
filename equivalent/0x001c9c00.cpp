// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001c9c00 @ 0x001c9c00
struct Argument { unsigned int value; void FUN_0027af50(); };
struct Object {
 unsigned int size, kind, field8, fieldC, field10, field14, field18, field1C;
 Object* FUN_001c9c00(Argument first, unsigned int second, unsigned int third);
};
Object* Object::FUN_001c9c00(Argument first, unsigned int second, unsigned int third) {
 size = 0; kind = 0; field8 = 0; fieldC = 0;
 field10 = 0; field14 = 0; field18 = 0; field1C = 0;
 size = 0x20; kind = 6;
 field18 = first.value;
 field1C = second;
 fieldC = third;
 first.FUN_0027af50();
 return this;
}