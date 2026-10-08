extern char gWaypoint[];
class CDHGameObjectCreator { char a[4]; };
class DataHandler { public: class ObjectCreator { char b[4]; }; };
class CAmbientsManager : public CDHGameObjectCreator, public DataHandler::ObjectCreator {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual const char* vfunc_3(void*);
};
const char* CAmbientsManager::vfunc_3(void*) { return gWaypoint; }