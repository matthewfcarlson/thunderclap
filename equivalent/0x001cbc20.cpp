// STATUS: equivalent (tools/equiv.py level 3: 66 inputs, branch coverage 4/4)
// FUN_001cbc20 @ 0x001cbc20
extern unsigned DAT_004d9968;
void __fastcall __security_check_cookie(unsigned cookie);
struct Record { unsigned size; char data[220]; };
struct Queue { char pad[16]; Record* next; Record* end; bool FUN_001cbc20(const Record* source); };
bool Queue::FUN_001cbc20(const Record* source) {
    unsigned cookie = DAT_004d9968;
    Record local;
    local.size = 0;
    unsigned n = source->size;
    const unsigned char* s = reinterpret_cast<const unsigned char*>(source);
    unsigned char* d = reinterpret_cast<unsigned char*>(&local);
    for (unsigned i=0; i<n; ++i) d[i]=s[i];
    Record* dest=next;
    bool result = false;
    if (dest < end) {
        next = dest + 1;
        if (dest) *dest=local;
        result = true;
    }
    __security_check_cookie(cookie);
    return result;
}
