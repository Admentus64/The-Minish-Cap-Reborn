#include "global.h"
#include "entity.h"

extern void sub_0806ED78();
extern void sub_08067C44();

extern void (*gCat[9])(Entity*);

// Main
void Cat(Entity* ent) {
    gCat[ent->action](ent);
    sub_08067C44(ent);
    if (((ent->flags & 128) == 0) && (ent->type != 5)) {
        sub_0806ED78(ent);
    }
}
