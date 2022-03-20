#define NENT_DEPRECATED
#include "entity.h"
#include "player.h"
#include "asm.h"
#include "functions.h"
#include "sound.h"
#include "item.h"
#include "flags.h"
#include "effects.h"

typedef struct _struct_gUnk_08123FB0 {
    void (*const funcEnt)(Entity*);
    bool32 (*const func)(Entity*, const struct _struct_gUnk_08123FB0*);
    s8 unk08;
    s8 unk09;
    u8 unk0a;
    u8 unk0b;
    u8 unk0c;
    u8 type;
    u8 unk0e;
    u8 unk0f;
    s32 zVelocity;
    u32 unk14;
    s16 speed;
    s16 y;
    u16 flag;
    u8 actionDelay;
    u8 unk1f;
} struct_gUnk_08123FB0;

static_assert(sizeof(struct_gUnk_08123FB0) == 0x20);

void sub_0809D91C(Entity*);
bool32 sub_0809D93C(Entity*, const struct_gUnk_08123FB0*);
void Object96_Init(Entity*, const struct_gUnk_08123FB0*);
void Object96_Action1(Entity*, const struct_gUnk_08123FB0*);
void Object96_Action2(Entity*, const struct_gUnk_08123FB0*);
void Object96_Action3(Entity*, const struct_gUnk_08123FB0*);

static const struct_gUnk_08123FB0 gUnk_08123FB0[] = {
    { sub_0809D91C, sub_0809D93C, 0, 0, 0x30, 0x30, 0x1, 0x3c, 0x3c, 0x13, 0x10000, 0x1800, 0x60, 0x40, 0x4021, 0x1,
      0x0 },
    { sub_0809D91C, NULL, 0, 0, 0, 0, 0, 0x63, 0x63, 0x10, 0, 0x1800, 0, 0x18,
#if defined(JP) || defined(DEMO_JP) || defined(EU)
      0xCD,
#else
      0xd0,
#endif
      0, 0 },
    { sub_0809D91C, NULL, 0, 0, 0, 0, 0, 0x3c, 0x3c, 0xf, 0x10000, 0x1800, 0x60, 0x40, 0x4021, 0x1, 0x0 },
    { sub_0809D91C, NULL, 0, 0, 0, 0, 0, 0x3c, 0x3c, 0x2, 0x10000, 0x1800, 0x140, 0x40, 0x4021, 0x1, 0x0 },
    { sub_0809D91C, NULL, 0, 0, 0, 0, 0x0, 0x3c, 0x3c, 0xd, 0x10000, 0x1800, 0x60, 0x40, 0x4021, 0x1, 0x0 },
    { sub_0809D91C, NULL, 0, 0, 0, 0, 0x0, 0x3c, 0x3c, 0x1a, 0x10000, 0x1800, 0x100, 0x40, 0x4021, 0x1, 0x0 },
    { sub_0809D91C, NULL, 0, 0, 0, 0, 0x0, 0x3c, 0x3c, 0x13, 0x10000, 0x1800, 0x60, 0x40, 0x4021, 0x1, 0x0 },
    { NULL, NULL, 0, 0, 0, 0, 0x0, 0x5c, 0x5c, 0x81, 0, 0x1800, 0x100, 0x20, 0x0, 0x1, 0x0 },
};

void Object96(Entity* this) {
    static void (*const actionFuncs[])(Entity*, const struct_gUnk_08123FB0*) = {
        Object96_Init,
        Object96_Action1,
        Object96_Action2,
        Object96_Action3,
    };
    actionFuncs[this->action](this, &gUnk_08123FB0[this->type]);
}

void Object96_Init(Entity* this, const struct_gUnk_08123FB0* param_2) {
    u32 type;
    u32 dir;

    this->action++;
    this->collisionLayer = 2;
    this->spriteRendering.b3 = 1;
    this->zVelocity = param_2->zVelocity;
    this->direction = param_2->unk0f;
    this->speed = param_2->speed;
    this->y.HALF.HI -= param_2->y;
    this->z.WORD = 0;
    this->actionDelay = param_2->actionDelay;
    if ((this->direction & 0x80)) {
        dir = this->direction;
        if (dir == 0x81) {
            this->direction = (((gPlayerEntity.animationState * 4 + (Random() & 3)) - 2) & 0x1f) ^ 0x10;
        }
    }
    UpdateSpriteForCollisionLayer(this);
    type = this->type;
    sub_08080CB4(this);
    this->type = type;
}

void Object96_Action1(Entity* this, const struct_gUnk_08123FB0* param_2) {
    u32 type;
    s32 iVar3;

    iVar3 = 1;
    if (param_2->func != NULL) {
        iVar3 = param_2->func(this, param_2);
    }
    if (iVar3 != 0) {
        this->action++;
        this->y.HALF.HI += param_2->y;
        this->z.HALF.HI -= param_2->y;
    }
    type = this->type;
    this->type = param_2->type;
    sub_08080CB4(this);
    this->type = type;
}

void Object96_Action2(Entity* this, const struct_gUnk_08123FB0* param_2) {
    u8 type;

    LinearMoveUpdate(this);
    if (sub_080044EC(this, param_2->unk14) < 2) {
        if (this->actionDelay) {
            this->actionDelay--;
            this->zVelocity = param_2->unk14 << 3;
        } else {
            this->action++;
            this->collisionLayer = gPlayerEntity.collisionLayer;
            UpdateSpriteForCollisionLayer(this);
            if (param_2->funcEnt != NULL) {
                param_2->funcEnt(this);
            }
        }
        SoundReq(SFX_RUPEE_BOUNCE);
    }
    type = this->type;
    this->type = param_2->type;
    sub_08080CB4(this);
    this->type = type;
}

void Object96_Action3(Entity* this, const struct_gUnk_08123FB0* param_2) {
    u8 type;

    if (gPlayerState.flags & 0x80) {
        sub_0800445C(this);
    } else {
        if (IsCollidingPlayer(this)) {
            CreateItemEntity(param_2->type, this->type2, 0);
            if (param_2->flag) {
                SetFlag(param_2->flag);
            }
            DeleteThisEntity();
        }
    }
    type = this->type;
    this->type = param_2->type;
    sub_08080CB4(this);
    this->type = type;
}

void sub_0809D91C(Entity* this) {
    Entity* fxEnt;

    fxEnt = CreateFx(this, FX_DASH, 0);
    if (fxEnt != NULL) {
        SortEntityBelow(this, fxEnt);
    }
    SoundReq(SFX_SECRET);
}

bool32 sub_0809D93C(Entity* this, const struct_gUnk_08123FB0* param_2) {
    u32 uVar1;

    if (gPlayerEntity.action == 6 && ((param_2->unk0c >> gPlayerEntity.animationState & 1) != 0)) {
        uVar1 = (gPlayerEntity.x.HALF.HI - this->x.HALF.HI) + param_2->unk08 + param_2->unk0a;
        if (param_2->unk0a * 2 <= (u16)uVar1) {
            return 0;
        }

        uVar1 = (gPlayerEntity.y.HALF.HI - (this->y.HALF.HI + param_2->y)) + param_2->unk09 + param_2->unk0b;
        if (param_2->unk0b * 2 > (u16)uVar1) {
            return 1;
        }
    }
    return 0;
}