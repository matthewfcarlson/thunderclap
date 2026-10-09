struct Part { void Init(); };
struct End { void Finish(); };
class GrappleExecuteTrack {
public:
 virtual void v0();
 char pad4[0x10]; Part p14; char pad18[0x0c]; Part p24;
 void Run();
};
void GrappleExecuteTrack::Run() {
 *(unsigned long*)this = 0x413738;
 ((Part*)((char*)this+0x24))->Init();
 ((Part*)((char*)this+0x14))->Init();
 ((End*)this)->Finish();
}