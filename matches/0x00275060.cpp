void FreeFinish();
class SaveGameOpenRequest {
public:
 int vptr; char pad4[8]; int fieldC; unsigned char field10; char pad11[3]; int field14; int field18;
 void init(int);
 SaveGameOpenRequest* FUN_00275060(int,int,unsigned char,int,int);
};
SaveGameOpenRequest* SaveGameOpenRequest::FUN_00275060(int a,int b,unsigned char c,int d,int e) {
 init(a);
 fieldC=b;
 vptr=0x42ba40;
 field10=c;
 field14=d;
 field18=e;
 FreeFinish();
 return this;
}
