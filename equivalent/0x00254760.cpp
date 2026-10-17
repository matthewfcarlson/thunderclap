// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00254760 @ 0x00254760
struct Id64 { unsigned int low, high; };
struct Temp { char data[32]; Temp* FUN_0023fc40(const char*, int); void FUN_00240060(); };
Id64 __cdecl FUN_002672f0(const char*, int, int);
inline void* operator new(unsigned int, void* place) { return place; }
struct SeqEventSilenceType {
    virtual void dummy();
    void FUN_002605e0(Temp*, const Id64*, int, int);
    SeqEventSilenceType* FUN_00254760();
};
SeqEventSilenceType* SeqEventSilenceType::FUN_00254760() {
    Id64 id = FUN_002672f0("SeqEventSilence", 0, 0);
    Temp temp;
    FUN_002605e0(temp.FUN_0023fc40("Silnce", 0), &id, 16, 4);
    temp.FUN_00240060();
    new (this) SeqEventSilenceType;
    return this;
}