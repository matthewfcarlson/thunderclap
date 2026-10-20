// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_002909c0 @ 0x002909c0
struct Buffer { void* begin; void* end; bool FUN_002909c0(unsigned count, unsigned value); };
void* __cdecl FUN_0008d6d0(unsigned size);
void __cdecl FUN_00290810(void* data, unsigned count, unsigned value);
bool Buffer::FUN_002909c0(unsigned count, unsigned value) {
    if (begin) return false;
    if (count) {
        void* data = FUN_0008d6d0(count * 16);
        begin = data;
        if (data) {
            end = (char*)data + count * 16;
            FUN_00290810(data, count, value);
            return true;
        }
    }
    begin = 0;
    end = 0;
    return false;
}