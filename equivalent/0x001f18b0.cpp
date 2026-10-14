// STATUS: equivalent (tools/equiv.py level 3: 648 inputs, branch coverage 11/12, incomplete)
// FUN_001f18b0 @ 0x001f18b0
struct Item {
    Item* FUN_001f06c0(const char* name, void* data, unsigned a, unsigned b, unsigned c);
};
struct Manager {
    void FUN_001ef260(Item* item);
};
extern Manager* DAT_004e3710;
extern unsigned DAT_004d9968;
extern void __fastcall __security_check_cookie(unsigned cookie);
extern void* __cdecl FUN_0008d710(unsigned size, unsigned tag);
void __stdcall FUN_001f18b0(const char* name, void* data, unsigned a, unsigned b, unsigned c) {
    unsigned cookie = DAT_004d9968;
    if (name && data) {
        Manager* manager = DAT_004e3710;
        if (manager) {
            char buffer[64] = {0};
            unsigned i = 0;
            do { buffer[i] = name[i]; } while (name[i++]);
            Item* item = (Item*)FUN_0008d710(40, 6);
            if (item) item = item->FUN_001f06c0(name, data, a, b, c);
            manager->FUN_001ef260(item);
        }
    }
    __security_check_cookie(cookie);
}
