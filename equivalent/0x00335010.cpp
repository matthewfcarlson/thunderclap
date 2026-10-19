// STATUS: equivalent (tools/equiv.py level 3: 92 inputs, branch coverage 11/12, incomplete)
// movie::BinkCallback::vfunc_3_adj8 @ 0x00335010
struct FileStream_335010 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual int GetBlockSize();
};
int __cdecl FUN_0026fd50(int, int);
int __cdecl FUN_00368660();
struct BinkRequest {
    char pad0[0x1c];
    int failed;
    int busy;
    unsigned int bytesRead;
    int pendingA;
    unsigned int elapsedTotal;
    char pad30[0x4];
    unsigned int elapsedA;
    unsigned int elapsedB;
    char pad3c[0x4];
    unsigned int peak;
    char pad44[0x4];
    unsigned int outstanding;
    FileStream_335010* stream;
    char pad50[0x4];
    int readStart;
    char pad58[0x4];
    int readEnd;
    int buffer;
    unsigned int ringStart;
    unsigned int ringEnd;
    char pad6c[0x4];
    unsigned int ringPos;
    unsigned int remaining;
    int pendingB;
    unsigned int startTime;
    // equiv-conv: FUN_00334b00 esi
    void FUN_00334b00();
};
struct BinkCallback {
    void OnReadComplete(BinkRequest* req);
};
void BinkCallback::OnReadComplete(BinkRequest* req) {
    int count = req->readEnd - req->readStart;
    if (count != 0x4000) {
        int expected = FUN_0026fd50(req->buffer, req->stream->GetBlockSize());
        if (count != expected) {
            req->busy = 0;
            req->failed = 1;
            return;
        }
    }
    req->bytesRead += count;
    req->readStart = req->readEnd;
    req->ringPos += count;
    if (req->ringPos >= req->ringEnd)
        req->ringPos = req->ringStart;
    req->remaining -= count;
    req->outstanding += count;
    if (req->outstanding > req->peak)
        req->peak = req->outstanding;
    req->startTime = FUN_00368660() - req->startTime;
    req->elapsedTotal += req->startTime;
    if (req->pendingB == 0 && req->pendingA == 0)
        req->elapsedA += req->startTime;
    else
        req->elapsedB += req->startTime;
    req->busy = 0;
    req->FUN_00334b00();
}
