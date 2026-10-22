class FileRequest_275570 {
  public:
    FileRequest_275570(void*);
    virtual void f();
};
class FileCancelRequest : public FileRequest_275570 {
  public:
    FileCancelRequest(void*);
    virtual void f();
};
void __cdecl init();
FileCancelRequest::FileCancelRequest(void* p) : FileRequest_275570(p) {
    init();
}