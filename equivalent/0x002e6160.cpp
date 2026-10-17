// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_002e6160 @ 0x002e6160
struct Buffer { void* data; void* end; bool FUN_002e6160(unsigned int count, int value); }; 
void* __cdecl FUN_0008d6d0(unsigned int size);
void __cdecl FUN_002e59b0(void* data, unsigned int count, int value);
bool Buffer::FUN_002e6160(unsigned int count, int value) {
    if (data) return false;
    if (count) {
        void* p = FUN_0008d6d0(count * 12);
        data = p;
        if (p) {
            end = (char*)p + count * 12;
            FUN_002e59b0(p, count, value);
            return true;
        }
    }
    data = 0;
    end = 0;
    return false;
}