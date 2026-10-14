extern unsigned __int64 GetId(const char* name);
extern unsigned int gId;
extern unsigned int gId2;
void FUN_0035e620() {
    unsigned __int64 id = GetId("ATGWorldCollision");
    gId = (unsigned int)id;
    gId2 = (unsigned int)(id >> 32);
}
