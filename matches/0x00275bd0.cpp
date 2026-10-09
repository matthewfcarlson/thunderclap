extern "C" void __stdcall BaseInit(void*);
extern "C" void InitMore();
extern "C" char* strncpy(char*, const char*, unsigned int);
class DriveFileDestroyRequest { public: char pad[0x10c]; DriveFileDestroyRequest* Run(int, char*); };
DriveFileDestroyRequest* DriveFileDestroyRequest::Run(int a, char* p) {
    BaseInit((void*)a);
    *(unsigned int*)this = 0x42bc60;
    InitMore();
    strncpy((char*)this + 0xc, p, 0x100);
    ((char*)this)[0x10c] = 0;
    return this;
}