// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_001dc810 @ 0x001dc810
struct Vector { unsigned int x, y, z; };
struct Attached_1dc810 { char pad[0x188]; Vector position; };
struct Entry_1dc810 { char pad[0x18]; Attached_1dc810* attached; char unknown[6]; short index; char tail[4]; };
struct Position_1dc810 { Vector value; unsigned int unknown; unsigned int flags; };
extern float DAT_004e26bc;
extern float DAT_004e26c0;
extern float DAT_004e26c4;
extern unsigned int DAT_004e26c8;
struct Object {
 char pad[0x608];
 Entry_1dc810 entries[2048];
 Position_1dc810 positions[1];
 int FUN_001dbfe0(unsigned int key);
 Vector* FUN_001dc810(Vector* output, unsigned int key);
};
Vector* Object::FUN_001dc810(Vector* output, unsigned int key) {
 int index = FUN_001dbfe0(key);
 if (index < 0) {
 output->x = 0x7f7fffff; output->y = 0x7f7fffff; output->z = 0x7f7fffff;
 return output;
 }
 if (!(DAT_004e26c8 & 1)) {
 DAT_004e26c8 |= 1;
 DAT_004e26bc = 3.402823466e+38f;
 DAT_004e26c0 = 3.402823466e+38f;
 DAT_004e26c4 = 3.402823466e+38f;
 }
 Entry_1dc810& entry = entries[index];
 Position_1dc810& position = positions[entry.index];
 Vector* source = &position.value;
 if ((position.flags & 1) && entry.attached) source = &entry.attached->position;
 output->x = source->x;
 output->y = source->y;
 output->z = source->z;
 return output;
}
