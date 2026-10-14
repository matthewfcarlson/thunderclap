// STATUS: equivalent (tools/equiv.py level 3: 2993 inputs, branch coverage 27/28, incomplete)
// FUN_0007bac0 @ 0x0007bac0
struct Object {
    virtual void unused();
    virtual void release();
    char pad04[12];
    int type;
    char pad14[36];
    int groupId;
    int subIndex;
    char pad40[28];
    int category;
};
struct Cell_7bac0 { int id; char pad04[8]; int count; char pad10[56]; };
struct Group_7bac0 { Cell_7bac0 cells[14]; };
struct Flags_7bac0 { unsigned char first, second; };
struct Manager_7bac0 {
    char pad00[0x1920];
    union {
        Group_7bac0 groups[7];
        struct { char padToFlags[0x1b72]; Flags_7bac0 flags[8]; } flagView;
    };
    char pad34b0[0x268];
    union {
        int categoryCounts[13];
        struct { char padToBefore[48]; Object* before; } tailView;
    };
    Object* objects[20];
    int count;
    int FUN_00079800(int key);
    int remove(int key);
};
int Manager_7bac0::remove(int key) {
    int index = FUN_00079800(key);
    if (index == -1) return index;
    --categoryCounts[objects[index]->category];
    Object* object = objects[index];
    int id = object->groupId;
    int group = -1;
    for (int i=0; i<7; ++i) {
        if (groups[i].cells[0].id == id) { group=i; break; }
    }
    if (group != -1) --groups[group].cells[object->subIndex].count;
    int type = objects[index]->type;
    if (type==5 || type==9 || type==7 || type==11)
        flagView.flags[group+1].first=0;
    else if (type==6 || type==10 || type==8 || type==12)
        flagView.flags[group+1].second=0;
    if (objects[index]) {
        objects[index]->release();
        objects[index]=0;
    }
    Object* last = count == 0 ? tailView.before : objects[count-1];
    if (last) {
        objects[index]=last;
        if (count == 0) tailView.before=0; else objects[count-1]=0;
    }
    return --count;
}
