extern "C" void InitOther();
extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);
class Base_275930 {
  public:
    virtual void V();
    Base_275930(int);
};
class DriveDestroyDirectoryRequest : public Base_275930 {
  public:
    virtual void W();
    char pad[8];
    char name[16];
    char tail;
    DriveDestroyDirectoryRequest(int, const char*);
};
DriveDestroyDirectoryRequest::DriveDestroyDirectoryRequest(int a, const char* s) : Base_275930(a) {
    InitOther();
    strncpy(name, s, 16);
    tail = 0;
}