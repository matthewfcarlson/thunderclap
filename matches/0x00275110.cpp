void __stdcall FUN_00274e60(void* p);
void __cdecl FUN_002705f0();
class FileCloseRequest {
  public:
    FileCloseRequest* Init(void* p);
    int m;
};
FileCloseRequest* FileCloseRequest::Init(void* p) {
    FUN_00274e60(p);
    *(volatile int*)this = 0x42ba60;
    FUN_002705f0();
    return this;
}
