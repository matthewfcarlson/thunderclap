class Request { public: char pad[8]; int field; };
class FileRequest : public Request { public: bool vfunc_2(int value); };
bool FileRequest::vfunc_2(int value) { return value == field; }