typedef unsigned int u32;
struct DataReader { char pad[8]; struct Helper* member; };
struct Helper { u32 call(u32,u32,u32,u32); };
struct StreamDataReader : DataReader { u32 vfunc_4(u32 a, u32 b); };
u32 StreamDataReader::vfunc_4(u32 a, u32 b) { member->call(a,b,1,1); return b; }
