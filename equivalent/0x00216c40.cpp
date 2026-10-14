// STATUS: equivalent (tools/equiv.py level 3: 114 inputs, branch coverage 43/44, incomplete)
// FUN_00216c40 @ 0x00216c40
struct Object { char pad[5]; unsigned char flags; };
struct Value_216c40 { int type; Object* object; };
struct Entry_216c40 { Value_216c40 key; Value_216c40 value; int extra; };
struct Table_216c40 { char pad0[5]; unsigned char flags; char pad6; unsigned char logSize; char pad8[4]; Value_216c40* array; Entry_216c40* entries; char pad14[4]; Table_216c40* next; unsigned int arraySize; };
// equiv-conv: FUN_00216c40 eax
void FUN_00216c40(Table_216c40* table) {
    while (table) {
        if (table->flags & 0x10) {
            unsigned int i = table->arraySize;
            while (i) {
                Value_216c40& v = table->array[--i];
                if (v.type == 4) v.object->flags &= 0xfc;
                else if (v.type > 4) {
                    unsigned char flags = v.object->flags;
                    if ((flags & 3) || (v.type == 7 && (flags & 8))) v.type = 0;
                }
            }
        }
        unsigned int count = 1u << (table->logSize & 31);
        while (count) {
            Entry_216c40& e = table->entries[--count];
            if (!e.value.type) continue;
            bool remove = false;
            if (e.key.type == 4) e.key.object->flags &= 0xfc;
            else if (e.key.type > 4 && (e.key.object->flags & 3)) remove = true;
            if (!remove) {
                if (e.value.type == 4) e.value.object->flags &= 0xfc;
                else if (e.value.type > 4) {
                    unsigned char flags = e.value.object->flags;
                    if ((flags & 3) || (e.value.type == 7 && (flags & 8))) remove = true;
                }
            }
            if (remove) {
                e.value.type = 0;
                if (e.key.type >= 4) e.key.type = -1;
            }
        }
        table = table->next;
    }
}
