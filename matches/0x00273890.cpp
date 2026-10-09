class Request { public: virtual void a(); };
class ObjV { public: virtual void a(); virtual void b(); };
class Inner { public: virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual void f(); virtual void g(); virtual int h(); int helper(); };
struct Data { char pad[4]; ObjV obj; char pad2[4]; Inner* inner; char pad3[4]; int value; };
class FileRequest : public Request { public: char pad[4]; Data* data; int vfunc_4(); };
int FileRequest::vfunc_4() { Inner* p=data->inner; int first=p->h(); int second=p->helper(); data->obj.a(); data->value=second; data->obj.b(); return first; }