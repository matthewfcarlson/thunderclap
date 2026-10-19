// STATUS: equivalent (tools/equiv.py level 3: 68 inputs, branch coverage 4/4)
// FUN_001cbc20 @ 0x001cbc20
// cl-flags: /GS
struct Record_1cbc20 { unsigned size; char data[220]; };
struct Queue_1cbc20 { char pad[16]; Record_1cbc20* next; Record_1cbc20* end; bool FUN_001cbc20(const Record_1cbc20* source); };
bool Queue_1cbc20::FUN_001cbc20(const Record_1cbc20* source) {
    Record_1cbc20 local;
    local.size = 0;
    unsigned n = source->size;
    const unsigned char* s = reinterpret_cast<const unsigned char*>(source);
    unsigned char* d = reinterpret_cast<unsigned char*>(&local);
    for (unsigned i=0; i<n; ++i) d[i]=s[i];
    Record_1cbc20* dest=next;
    bool result = false;
    if (dest < end) {
        next = dest + 1;
        if (dest) *dest=local;
        result = true;
    }
    return result;
}
