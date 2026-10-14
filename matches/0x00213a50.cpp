// cl-flags: /O2 /GR /GX

struct BufferHeader {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    int field_18;
};

struct DataItem {
    int* ptr0;
    int* ptr4;
};

struct Entry_213a50 {
    int type;
    int next;
    char pad[4];
    int data;
};

extern "C" Entry_213a50* __cdecl FUN_00219520(BufferHeader* buf, int zero);
extern "C" void __cdecl FUN_00215460(BufferHeader* buf, int flag);
extern "C" void __cdecl FUN_002159e0(BufferHeader* buf, Entry_213a50* entry, int zero);

void FUN_00213a50(BufferHeader* buf, DataItem* item) {
    Entry_213a50* entry = FUN_00219520(buf, 0);

    entry->data = (int)item->ptr0;

    int* writePtr = (int*)buf->field_8;
    writePtr[1] = (int)entry;
    *writePtr = 6;

    int available = buf->field_18 - buf->field_8;
    if (available <= 8) {
        FUN_00215460(buf, 1);
    }

    buf->field_8 += 8;

    int* slot2 = (int*)buf->field_8;
    slot2[1] = (int)item->ptr4;
    *slot2 = 2;

    available = buf->field_18 - buf->field_8;
    if (available <= 8) {
        FUN_00215460(buf, 1);
    }

    buf->field_8 += 8;

    Entry_213a50* entry3 = (Entry_213a50*)(buf->field_8 - 0x10);
    FUN_002159e0(buf, entry3, 0);
}