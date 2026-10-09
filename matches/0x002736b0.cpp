extern void* vFileCompletion;
extern void* vRequest;
class Obj { public: virtual void f(); virtual void g(); };
class FileCompletionRequest { public: void** vt; char pad[8]; Obj* m0c; Obj* m10; void Finish(); };
void FileCompletionRequest::Finish() { vt = &vFileCompletion; m10->g(); m0c->g(); vt = &vRequest; }
