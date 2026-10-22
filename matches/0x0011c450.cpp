extern void* g_vftable_11c450[];
void Free(void*) throw();
class Track_11c450 {
  public:
    void* vptr;
    void Fin();
};
class PathFormationTrack_11c450 : public Track_11c450 {
  public:
    char pad[0x30];
    void* m34;
    ~PathFormationTrack_11c450() throw();
};
PathFormationTrack_11c450::~PathFormationTrack_11c450() throw() {
    void* t = m34;
    vptr = g_vftable_11c450;
    Free(t);
    Fin();
}
