// STATUS: equivalent (tools/equiv.py level 3: 3042 inputs, branch coverage 22/22)
// FUN_001a5340 @ 0x001a5340
struct Entry_1a5340 { unsigned int value; char padding[12]; };
struct Data_1a5340 { char padding[0x64]; Entry_1a5340 entries[20]; };
struct Object { char padding[0x1c]; Data_1a5340* data; unsigned int FUN_001a5340(unsigned int index); };
unsigned int Object::FUN_001a5340(unsigned int index) { if (index > 19) return 1; return data->entries[index].value; }
