struct Elem { void D(); };
struct E16 { char p[16]; };
struct E8 { char p[8]; };
namespace DataHandler { class ObjectCreator { public: virtual void f(); virtual ~ObjectCreator() throw() {} }; }
class CAmbientsManager : public DataHandler::ObjectCreator {
public:
    virtual void f();
    virtual ~CAmbientsManager() throw();
    char pad[0x34a8 - 4];
    E16 a[10];
    char pad2[0x35a0 - 0x3548];
    E8 b[20];
    E16 c[10];
};
CAmbientsManager::~CAmbientsManager() throw() {
    E16* p = (E16*)((char*)this + 0x36f0);
    int i = 10;
    do { p--; ((Elem*)p)->D(); i--; } while (i != 0);
    E8* q = (E8*)((char*)this + 0x3640);
    i = 20;
    do { q--; ((Elem*)q)->D(); i--; } while (i != 0);
    p = (E16*)((char*)this + 0x3548);
    i = 10;
    do { p--; ((Elem*)p)->D(); i--; } while (i != 0);
}
