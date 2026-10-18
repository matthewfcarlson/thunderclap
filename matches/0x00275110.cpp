extern "C" char DAT_0042ba60[];
struct Request_275110 {
    Request_275110* FUN_00274e60(void* p);
};
void __cdecl FUN_002705f0();
class FileCloseRequest {
  public:
    FileCloseRequest* Init(void* p);
    int m;
};
FileCloseRequest* FileCloseRequest::Init(void* p) {
    ((Request_275110*)this)->FUN_00274e60(p);
    *(volatile int*)this = ((int)DAT_0042ba60);
    FUN_002705f0();
    return this;
}
