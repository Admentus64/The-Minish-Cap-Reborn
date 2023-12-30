// TODO belongs to game.c, but spriteAnimations332.s is before.
// maybe also signals code that no longer belongs to game.c?
#include "common.h"
#include "flags.h"
#include "game.h"
#include "item.h"
#include "kinstone.h"
#include "room.h"

// extern const u8 gUnk_080FE1B4[];
// const u8 gUnk_080FE1B4[] = {0, 84, 85, 86, 95, 96, 93, 94, 63, 252, 253, 254, 255, 0, 0, 0,0,};
const u8 gUnk_080FE1B4[] = {
    ITEM_NONE,         ITEM_RUPEE1,  ITEM_RUPEE5, ITEM_RUPEE20,      ITEM_HEART,         ITEM_FAIRY,
    ITEM_BOMBS5,       ITEM_ARROWS5, ITEM_SHELLS, ITEM_KINSTONE_RED, ITEM_KINSTONE_BLUE, ITEM_KINSTONE_GREEN,
    ITEM_ENEMY_BEETLE, ITEM_NONE,    ITEM_NONE,   ITEM_NONE,         ITEM_NONE,          ITEM_NONE,
};
const u8 gUnk_080FE1C6[] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 9, 10, 10, 11, 12, 13, 14, 15, 8, 15, 1, 8,
};
const u8 gUnk_080FE1DD[3][0x40] = {
    { 0x6E, 0x6F, 0x70, 0x70, 0x6E, 0x6F, 0x6F, 0x70, 0x6E, 0x6E, 0x70, 0x6F, 0x70, 0x6F, 0x6E, 0x6E,
      0x6E, 0x6F, 0x70, 0x70, 0x6E, 0x6F, 0x6F, 0x70, 0x6E, 0x6E, 0x70, 0x6F, 0x70, 0x6F, 0x6E, 0x6F,
      0x6E, 0x6F, 0x70, 0x70, 0x6E, 0x6F, 0x6F, 0x70, 0x6E, 0x6E, 0x70, 0x6F, 0x70, 0x6F, 0x6E, 0x70,
      0x6E, 0x6F, 0x70, 0x70, 0x6E, 0x6F, 0x6F, 0x70, 0x6E, 0x6E, 0x70, 0x6F, 0x70, 0x6F, 0x6E, 0x00 },
    { 0x71, 0x72, 0x71, 0x72, 0x71, 0x72, 0x71, 0x72, 0x71, 0x72, 0x71, 0x72, 0x71, 0x72, 0x71, 0x72,
      0x71, 0x72, 0x71, 0x72, 0x71, 0x72, 0x71, 0x72, 0x71, 0x72, 0x71, 0x72, 0x71, 0x72, 0x71, 0x72,
      0x71, 0x72, 0x71, 0x72, 0x71, 0x72, 0x71, 0x72, 0x71, 0x72, 0x71, 0x72, 0x71, 0x72, 0x71, 0x72,
      0x71, 0x72, 0x71, 0x72, 0x71, 0x72, 0x71, 0x72, 0x71, 0x72, 0x71, 0x72, 0x71, 0x72, 0x71, 0x72 },
    { 0x73, 0x74, 0x75, 0x75, 0x73, 0x74, 0x74, 0x75, 0x73, 0x73, 0x75, 0x74, 0x75, 0x74, 0x73, 0x73,
      0x73, 0x74, 0x75, 0x75, 0x73, 0x74, 0x74, 0x75, 0x73, 0x73, 0x75, 0x74, 0x75, 0x74, 0x73, 0x74,
      0x73, 0x74, 0x75, 0x75, 0x73, 0x74, 0x74, 0x75, 0x73, 0x73, 0x75, 0x74, 0x75, 0x74, 0x73, 0x75,
      0x73, 0x74, 0x75, 0x75, 0x73, 0x74, 0x74, 0x75, 0x73, 0x73, 0x75, 0x74, 0x75, 0x74, 0x73, 0x00 },
};
const u8 gPadding[3] = { 0, 0, 0 };

void Subtask_WorldEvent_Init(void);
void Subtask_WorldEvent_Update(void);
void Subtask_WorldEvent_End(void);
void (*const gUnk_080FE2A0[])(void) = {
    Subtask_WorldEvent_Init,
    Subtask_WorldEvent_Update,
    Subtask_WorldEvent_End,
};
void WorldEvent_0(void);
void WorldEvent_1(void);
void WorldEvent_2(void);
void WorldEvent_3(void);
void WorldEvent_4(void);
void WorldEvent_5(void);
void WorldEvent_6(void);
void WorldEvent_7(void);
void WorldEvent_8(void);
void WorldEvent_9(void);
void WorldEvent_Beanstalk(void);
void WorldEvent_11(void);
void WorldEvent_12(void);
void WorldEvent_13(void);
void WorldEvent_14(void);
void WorldEvent_15(void);
void WorldEvent_16(void);
void WorldEvent_17(void);
void WorldEvent_17(void);
void WorldEvent_19(void);
void WorldEvent_20(void);
void WorldEvent_21(void);
void WorldEvent_22(void);
void WorldEvent_23(void);
void WorldEvent_24(void);
void WorldEvent_25(void);

void (*const gWorldEventFunctions[])(void) = {
    WorldEvent_0,  WorldEvent_1,  WorldEvent_2,  WorldEvent_3,  WorldEvent_4,         WorldEvent_5,
    WorldEvent_6,  WorldEvent_7,  WorldEvent_8,  WorldEvent_9,  WorldEvent_Beanstalk, WorldEvent_11,
    WorldEvent_12, WorldEvent_13, WorldEvent_14, WorldEvent_15, WorldEvent_16,        WorldEvent_17,
    WorldEvent_17, WorldEvent_19, WorldEvent_20, WorldEvent_21, WorldEvent_22,        WorldEvent_23,
    WorldEvent_24, WorldEvent_25, WorldEvent_0,  WorldEvent_0,  WorldEvent_0,
};

// Indexed by worldEventId of gKinstoneWorldEvents
const WorldEvent gWorldEvents[] = {
    { WORLD_EVENT_TYPE_0, 0, 0, 0, 0, 0, 0, 0, 0, 0, CND_0, 0, 0 },
    { WORLD_EVENT_TYPE_1, 0, AREA_RUINS, ROOM_RUINS_BELOW_FORTRESS_ENTRANCE, 128, 112, 248, 216, 728, 3112, CND_1,
      LOCAL_BANK_0, OUGONTEKI_A },
    { WORLD_EVENT_TYPE_1, 1, AREA_MT_CRENEL, ROOM_MT_CRENEL_CENTER, 384, 192, 504, 280, 488, 1112, CND_1, LOCAL_BANK_0,
      OUGONTEKI_B },
    { WORLD_EVENT_TYPE_1, 2, AREA_CASTOR_WILDS, ROOM_CASTOR_WILDS_MAIN, 480, 80, 600, 168, 600, 1848, CND_1,
      LOCAL_BANK_0, OUGONTEKI_C },
    { WORLD_EVENT_TYPE_1, 3, AREA_HYRULE_FIELD, ROOM_HYRULE_FIELD_EASTERN_HILLLS_NORTH, 0, 352, 120, 440, 2616, 2600,
      CND_1, LOCAL_BANK_0, OUGONTEKI_D },
    { WORLD_EVENT_TYPE_1, 4, AREA_CASTLE_GARDEN, ROOM_CASTLE_GARDEN_MAIN, 768, 160, 936, 248, 2424, 440, CND_1,
      LOCAL_BANK_0, OUGONTEKI_E },
    { WORLD_EVENT_TYPE_1, 5, AREA_VEIL_FALLS, ROOM_VEIL_FALLS_MAIN, 224, 144, 344, 232, 2840, 472, CND_1, LOCAL_BANK_0,
      OUGONTEKI_F },
    { WORLD_EVENT_TYPE_1, 6, AREA_MT_CRENEL, ROOM_MT_CRENEL_CAVERN_OF_FLAMES_ENTRANCE, 96, 368, 216, 456, 600, 680,
      CND_1, LOCAL_BANK_0, OUGONTEKI_G },
    { WORLD_EVENT_TYPE_1, 7, AREA_MINISH_WOODS, ROOM_MINISH_WOODS_MAIN, 192, 96, 328, 184, 3304, 2344, CND_1,
      LOCAL_BANK_0, OUGONTEKI_H },
    { WORLD_EVENT_TYPE_1, 8, AREA_HYRULE_FIELD, ROOM_HYRULE_FIELD_WESTERN_WOODS_CENTER, 176, 0, 312, 88, 1320, 2888,
      CND_1, LOCAL_BANK_0, OUGONTEKI_I },
    { WORLD_EVENT_TYPE_2, 0, AREA_HYRULE_FIELD, ROOM_HYRULE_FIELD_EASTERN_HILLLS_NORTH, 80, 288, 200, 376, 2696, 2536,
      CND_1, LOCAL_BANK_1, KAKERA_TAKARA_A },
    { WORLD_EVENT_TYPE_2, 0, AREA_CRENEL_MINISH_PATHS, ROOM_CRENEL_MINISH_PATHS_RAIN, 272, 16, 392, 88, 744, 152, CND_1,
      LOCAL_BANK_3, KAKERA_TAKARA_B },
    { WORLD_EVENT_TYPE_2, 0, AREA_CRENEL_MINISH_PATHS, ROOM_CRENEL_MINISH_PATHS_SPRING_WATER, 0, 48, 168, 136, 872,
      1432, CND_1, LOCAL_BANK_3, KAKERA_TAKARA_C },
    { WORLD_EVENT_TYPE_2, 0, AREA_MINISH_PATHS, ROOM_MINISH_PATHS_SCHOOLYARD, 0, 240, 120, 328, 2408, 1608, CND_1,
      LOCAL_BANK_3, KAKERA_TAKARA_D },
    { WORLD_EVENT_TYPE_2, 0, AREA_MINISH_WOODS, ROOM_MINISH_WOODS_MAIN, 0, 112, 104, 200, 3080, 2360, CND_1,
      LOCAL_BANK_1, KAKERA_TAKARA_E },
    { WORLD_EVENT_TYPE_2, 0, AREA_MINISH_PATHS, ROOM_MINISH_PATHS_LON_LON_RANCH, 0, 288, 120, 376, 2968, 1544, CND_1,
      LOCAL_BANK_3, KAKERA_TAKARA_F },
    { WORLD_EVENT_TYPE_2, 0, AREA_MINISH_PATHS, ROOM_MINISH_PATHS_MINISH_VILLAGE, 0, 416, 104, 504, 3448, 3064, CND_1,
      LOCAL_BANK_3, KAKERA_TAKARA_G },
    { WORLD_EVENT_TYPE_2, 0, AREA_CRENEL_MINISH_PATHS, ROOM_CRENEL_MINISH_PATHS_MELARI, 208, 16, 344, 104, 616, 504,
      CND_1, LOCAL_BANK_3, KAKERA_TAKARA_H },
    { WORLD_EVENT_TYPE_2, 0, AREA_MINISH_PATHS, ROOM_MINISH_PATHS_LAKE_HYLIA, 0, 640, 104, 760, 3896, 2024, CND_1,
      LOCAL_BANK_3, KAKERA_TAKARA_I },
    { WORLD_EVENT_TYPE_2, 0, AREA_MINISH_WOODS, ROOM_MINISH_WOODS_MAIN, 0, 576, 88, 664, 3064, 2824, CND_1,
      LOCAL_BANK_1, KAKERA_TAKARA_J },
    { WORLD_EVENT_TYPE_2, 0, AREA_RUINS, ROOM_RUINS_FORTRESS_ENTRANCE, 288, 80, 488, 168, 968, 2808, CND_1,
      LOCAL_BANK_1, KAKERA_TAKARA_K },
    { WORLD_EVENT_TYPE_2, 0, AREA_MINISH_WOODS, ROOM_MINISH_WOODS_MAIN, 768, 496, 904, 584, 3880, 2744, CND_1,
      LOCAL_BANK_1, KAKERA_TAKARA_L },
    { WORLD_EVENT_TYPE_2, 0, AREA_HYRULE_FIELD, ROOM_HYRULE_FIELD_TRILBY_HIGHLANDS, 240, 0, 392, 56, 1400, 1256, CND_1,
      LOCAL_BANK_1, KAKERA_TAKARA_M },
    { WORLD_EVENT_TYPE_2, 0, AREA_MINISH_WOODS, ROOM_MINISH_WOODS_MAIN, 544, 640, 664, 728, 3640, 2888, CND_1,
      LOCAL_BANK_1, KAKERA_TAKARA_N },
    { WORLD_EVENT_TYPE_2, 0, AREA_MINISH_WOODS, ROOM_MINISH_WOODS_MAIN, 48, 320, 200, 360, 3176, 2520, CND_1,
      LOCAL_BANK_1, KAKERA_TAKARA_O },
    { WORLD_EVENT_TYPE_2, 0, AREA_HYRULE_FIELD, ROOM_HYRULE_FIELD_SOUTH_HYRULE_FIELD, 656, 272, 776, 360, 2264, 2840,
      CND_1, LOCAL_BANK_1, KAKERA_TAKARA_P },
    { WORLD_EVENT_TYPE_2, 0, AREA_ROYAL_VALLEY, ROOM_ROYAL_VALLEY_MAIN, 0, 0, 56, 88, 1064, 280, CND_1, LOCAL_BANK_1,
      KAKERA_TAKARA_Q },
    { WORLD_EVENT_TYPE_2, 0, AREA_ROYAL_VALLEY, ROOM_ROYAL_VALLEY_MAIN, 240, 0, 424, 88, 1432, 280, CND_1, LOCAL_BANK_1,
      KAKERA_TAKARA_R },
    { WORLD_EVENT_TYPE_2, 0, AREA_HYRULE_FIELD, ROOM_HYRULE_FIELD_TRILBY_HIGHLANDS, 144, 352, 280, 440, 1288, 1640,
      CND_1, LOCAL_BANK_1, KAKERA_TAKARA_S },
    { WORLD_EVENT_TYPE_2, 0, AREA_HYRULE_FIELD, ROOM_HYRULE_FIELD_NORTH_HYRULE_FIELD, 0, 0, 104, 72, 1592, 792, CND_1,
      LOCAL_BANK_1, KAKERA_TAKARA_T },
    { WORLD_EVENT_TYPE_2, 0, AREA_HYRULE_FIELD, ROOM_HYRULE_FIELD_LON_LON_RANCH, 48, 0, 168, 40, 2664, 1240, CND_1,
      LOCAL_BANK_1, KAKERA_TAKARA_U },
    { WORLD_EVENT_TYPE_2, 0, AREA_VEIL_FALLS, ROOM_VEIL_FALLS_MAIN, 240, 96, 360, 184, 2856, 376, CND_1, LOCAL_BANK_1,
      KAKERA_TAKARA_V },
    { WORLD_EVENT_TYPE_2, 0, AREA_MT_CRENEL, ROOM_MT_CRENEL_WALL_CLIMB, 48, 288, 184, 376, 184, 600, CND_1,
      LOCAL_BANK_1, KAKERA_TAKARA_W },
    { WORLD_EVENT_TYPE_2, 0, AREA_MT_CRENEL, ROOM_MT_CRENEL_ENTRANCE, 0, 0, 120, 88, 120, 1288, CND_1, LOCAL_BANK_1,
      KAKERA_TAKARA_X },
    { WORLD_EVENT_TYPE_2, 0, AREA_RUINS, ROOM_RUINS_LADDER_TO_TEKTITES, 0, 0, 136, 88, 376, 3096, CND_1, LOCAL_BANK_1,
      KAKERA_TAKARA_Y },
    { WORLD_EVENT_TYPE_0, 0, AREA_MINISH_WOODS, ROOM_MINISH_WOODS_MAIN, 0, 0, 0, 0, 0, 0, CND_0, 0, 0 },
    { WORLD_EVENT_TYPE_3, 0, AREA_RUINS, ROOM_RUINS_ENTRANCE, 0, 48, 40, 136, 40, 2776, CND_2, 0,
      ITEM_ARROW_BUTTERFLY },
    { WORLD_EVENT_TYPE_3, 1, AREA_CASTOR_WILDS, ROOM_CASTOR_WILDS_MAIN, 304, 448, 424, 520, 424, 2200, CND_2, 0,
      ITEM_DIG_BUTTERFLY },
    { WORLD_EVENT_TYPE_3, 2, AREA_ROYAL_VALLEY, ROOM_ROYAL_VALLEY_MAIN, 0, 136, 56, 216, 1064, 408, CND_2, 0,
      ITEM_SWIM_BUTTERFLY },
#if defined(EU) || defined(JP) || defined(DEMO_JP)
    { WORLD_EVENT_TYPE_4, 0, AREA_HYRULE_FIELD, ROOM_HYRULE_FIELD_TRILBY_HIGHLANDS, 112, 160, 264, 264, 1272, 1432,
      CND_0, 0, 0 },
    { WORLD_EVENT_TYPE_4, 0, AREA_LAKE_HYLIA, ROOM_LAKE_HYLIA_MAIN, 352, 400, 488, 520, 3704, 1688, CND_0, 0, 0 },
#ifdef DEMO_JP
    { WORLD_EVENT_TYPE_4, 0, AREA_VEIL_FALLS, ROOM_VEIL_FALLS_MAIN, 160, 576, 232, 664, 2728, 824, CND_1, LOCAL_BANK_3,
      MOGURA_41_T3 }, // same as USA
#else
    { WORLD_EVENT_TYPE_4, 0, AREA_VEIL_FALLS, ROOM_VEIL_FALLS_MAIN, 160, 576, 232, 664, 2728, 824, CND_0, 0, 0 },
#endif
    { WORLD_EVENT_TYPE_5, 132, AREA_CASTLE_GARDEN, ROOM_CASTLE_GARDEN_MAIN, 656, 0, 776, 72, 2264, 264, CND_0, 0, 0 },
#ifdef DEMO_JP
    { WORLD_EVENT_TYPE_5, 1, AREA_HYRULE_FIELD, ROOM_HYRULE_FIELD_LON_LON_RANCH, 384, 440, 504, 520, 3000, 1720, CND_1,
      LOCAL_BANK_4, 0x4c }, // TODO differs from USA
#else
    { WORLD_EVENT_TYPE_5, 1, AREA_HYRULE_FIELD, ROOM_HYRULE_FIELD_LON_LON_RANCH, 384, 440, 504, 520, 3000, 1720, CND_0,
      0, 0 },
#endif
    { WORLD_EVENT_TYPE_5, 2, AREA_HYRULE_FIELD, ROOM_HYRULE_FIELD_SOUTH_HYRULE_FIELD, 0, 200, 88, 280, 1576, 2760,
      CND_0, 0, 0 },
    { WORLD_EVENT_TYPE_5, 3, AREA_HYRULE_FIELD, ROOM_HYRULE_FIELD_TRILBY_HIGHLANDS, 0, 600, 56, 680, 1064, 1880, CND_0,
      0, 0 },
    { WORLD_EVENT_TYPE_5, 128, AREA_CASTLE_GARDEN, ROOM_CASTLE_GARDEN_MAIN, 128, 0, 232, 72, 1720, 264, CND_0, 0, 0 },
    { WORLD_EVENT_TYPE_6, 0, AREA_HYRULE_FIELD, ROOM_HYRULE_FIELD_WESTERN_WOODS_NORTH, 112, 224, 216, 296, 1240, 2488,
      CND_0, 0, 0 },
    { WORLD_EVENT_TYPE_6, 0, AREA_HYRULE_FIELD, ROOM_HYRULE_FIELD_WESTERN_WOODS_NORTH, 56, 32, 168, 88, 1192, 2280,
      CND_0, 0, 0 },
    { WORLD_EVENT_TYPE_6, 0, AREA_HYRULE_FIELD, ROOM_HYRULE_FIELD_WESTERN_WOODS_NORTH, 240, 448, 392, 552, 1416, 2744,
      CND_0, 0, 0 },
    { WORLD_EVENT_TYPE_6, 0, AREA_HYRULE_FIELD, ROOM_HYRULE_FIELD_WESTERN_WOODS_NORTH, 0, 464, 24, 568, 1048, 2760,
      CND_0, 0, 0 },
    { WORLD_EVENT_TYPE_7, 128, AREA_HYRULE_FIELD, ROOM_HYRULE_FIELD_NORTH_HYRULE_FIELD, 448, 224, 576, 296, 2072, 1016,
      CND_0, 0, 0 },
    { WORLD_EVENT_TYPE_7, 128, AREA_HYRULE_FIELD, ROOM_HYRULE_FIELD_NORTH_HYRULE_FIELD, 304, 304, 432, 392, 1928, 1112,
      CND_0, 0, 0 },
    { WORLD_EVENT_TYPE_7, 128, AREA_HYRULE_FIELD, ROOM_HYRULE_FIELD_NORTH_HYRULE_FIELD, 328, 224, 432, 296, 1928, 1016,
      CND_0, 0, 0 },
    { WORLD_EVENT_TYPE_7, 128, AREA_HYRULE_FIELD, ROOM_HYRULE_FIELD_NORTH_HYRULE_FIELD, 448, 328, 576, 392, 2072, 1112,
      CND_0, 0, 0 },
#ifdef DEMO_JP
    { WORLD_EVENT_TYPE_7, 0, AREA_HYRULE_FIELD, ROOM_HYRULE_FIELD_WESTERN_WOODS_NORTH, 40, 408, 160, 488, 1160, 2648,
      CND_1, LOCAL_BANK_2, URO_19_H0 }, // same as USA
#else
    { WORLD_EVENT_TYPE_7, 0, AREA_HYRULE_FIELD, ROOM_HYRULE_FIELD_WESTERN_WOODS_NORTH, 40, 408, 160, 488, 1160, 2648,
      CND_0, 0, 0 },
#endif
    { WORLD_EVENT_TYPE_7, 1, AREA_MINISH_WOODS, ROOM_MINISH_WOODS_MAIN, 408, 376, 528, 456, 3496, 2600, CND_0, 0, 0 },
    { WORLD_EVENT_TYPE_7, 2, AREA_HYRULE_FIELD, ROOM_HYRULE_FIELD_NORTH_HYRULE_FIELD, 632, 232, 752, 312, 2248, 1032,
      CND_0, 0, 0 },
    { WORLD_EVENT_TYPE_7, 3, AREA_HYRULE_FIELD, ROOM_HYRULE_FIELD_SOUTH_HYRULE_FIELD, 768, 472, 928, 552, 2424, 3032,
      CND_0, 0, 0 },
    { WORLD_EVENT_TYPE_8, 0, AREA_RUINS, ROOM_RUINS_TEKTITES, 0, 0, 200, 88, 440, 2936, CND_0, 0, 0 },
    { WORLD_EVENT_TYPE_8, 0, AREA_MINISH_WOODS, ROOM_MINISH_WOODS_MAIN, 496, 848, 536, 968, 3512, 3128, CND_0, 0, 0 },
    { WORLD_EVENT_TYPE_8, 0, AREA_CASTOR_WILDS, ROOM_CASTOR_WILDS_MAIN, 0, 16, 24, 88, 24, 1768, CND_0, 0, 0 },
    { WORLD_EVENT_TYPE_8, 0, AREA_LAKE_HYLIA, ROOM_LAKE_HYLIA_MAIN, 48, 424, 152, 520, 3368, 1720, CND_0, 0, 0 },

#ifdef DEMO_JP
    // mostly same as USA
    { WORLD_EVENT_TYPE_9, 0, AREA_VEIL_FALLS, ROOM_VEIL_FALLS_MAIN, 0, 0, 56, 40, 2552, 232, CND_1, LOCAL_BANK_4,
      SUIGEN_DOUKUTU_09_H00 },
    { WORLD_EVENT_TYPE_9, 1, AREA_HYRULE_TOWN, ROOM_HYRULE_TOWN_MAIN, 112, 304, 240, 392, 1736, 1912, CND_0, 0,
      0 }, // same as EU
    { WORLD_EVENT_TYPE_25, 0, AREA_CASTOR_WILDS, ROOM_CASTOR_WILDS_MAIN, 768, 0, 920, 56, 920, 1752, CND_2, 0,
      ITEM_SKILL_FAST_SPIN },
    { WORLD_EVENT_TYPE_25, 1, AREA_HYRULE_FIELD, ROOM_HYRULE_FIELD_NORTH_HYRULE_FIELD, 80, 400, 200, 488, 1688, 1208,
      CND_2, 0, ITEM_SKILL_LONG_SPIN },
    { WORLD_EVENT_TYPE_25, 2, AREA_VEIL_FALLS, ROOM_VEIL_FALLS_MAIN, 128, 752, 248, 840, 2744, 1032, CND_2, 0,
      ITEM_SKILL_FAST_SPLIT },
    { WORLD_EVENT_TYPE_BEANSTALK, 0, AREA_MT_CRENEL, ROOM_MT_CRENEL_TOP, 0, 0, 152, 40, 152, 40, CND_5, LOCAL_BANK_1,
      BEANDEMO_00 }, // uses different flags due to CND_5
    { WORLD_EVENT_TYPE_BEANSTALK, 0, AREA_LAKE_HYLIA, ROOM_LAKE_HYLIA_BEANSTALK, 432, 0, 552, 88, 3528, 1096, CND_6,
      LOCAL_BANK_1, BEANDEMO_01 }, // uses different flags due to CND_6
    { WORLD_EVENT_TYPE_BEANSTALK, 0, AREA_RUINS, ROOM_RUINS_BEANSTALK, 0, 0, 72, 72, 312, 2712, CND_7, LOCAL_BANK_1,
      BEANDEMO_02 }, // uses different flags due to CND_7
    { WORLD_EVENT_TYPE_BEANSTALK, 0, AREA_HYRULE_FIELD, ROOM_HYRULE_FIELD_EASTERN_HILLLS_CENTER, 0, 0, 72, 56, 2568,
      2760, CND_8, LOCAL_BANK_1, BEANDEMO_03 }, // uses different flags due to CND_8
    { WORLD_EVENT_TYPE_BEANSTALK, 0, AREA_HYRULE_FIELD, ROOM_HYRULE_FIELD_WESTERN_WOODS_SOUTH, 0, 0, 56, 56, 1064, 3016,
      CND_9, LOCAL_BANK_1, BEANDEMO_04 }, // uses different flags due to CND_9
#else
    { WORLD_EVENT_TYPE_9, 0, AREA_VEIL_FALLS, ROOM_VEIL_FALLS_MAIN, 0, 0, 56, 40, 2552, 232, CND_0, 0, 0 },
    { WORLD_EVENT_TYPE_9, 1, AREA_HYRULE_TOWN, ROOM_HYRULE_TOWN_MAIN, 112, 304, 240, 392, 1736, 1912, CND_0, 0, 0 },
    { WORLD_EVENT_TYPE_25, 0, AREA_CASTOR_WILDS, ROOM_CASTOR_WILDS_MAIN, 768, 0, 920, 56, 920, 1752, CND_0, 0, 0 },
    { WORLD_EVENT_TYPE_25, 1, AREA_HYRULE_FIELD, ROOM_HYRULE_FIELD_NORTH_HYRULE_FIELD, 80, 400, 200, 488, 1688, 1208,
      CND_0, 0, 0 },
    { WORLD_EVENT_TYPE_25, 2, AREA_VEIL_FALLS, ROOM_VEIL_FALLS_MAIN, 128, 752, 248, 840, 2744, 1032, CND_0, 0, 0 },
    { WORLD_EVENT_TYPE_BEANSTALK, 0, AREA_MT_CRENEL, ROOM_MT_CRENEL_TOP, 0, 0, 152, 40, 152, 40, CND_0, LOCAL_BANK_1,
      BEANDEMO_00 }, // uses different flags due to CND_5
    { WORLD_EVENT_TYPE_BEANSTALK, 0, AREA_LAKE_HYLIA, ROOM_LAKE_HYLIA_BEANSTALK, 432, 0, 552, 88, 3528, 1096, CND_0,
      LOCAL_BANK_1, BEANDEMO_01 }, // uses different flags due to CND_6
    { WORLD_EVENT_TYPE_BEANSTALK, 0, AREA_RUINS, ROOM_RUINS_BEANSTALK, 0, 0, 72, 72, 312, 2712, CND_0, LOCAL_BANK_1,
      BEANDEMO_02 }, // uses different flags due to CND_7
    { WORLD_EVENT_TYPE_BEANSTALK, 0, AREA_HYRULE_FIELD, ROOM_HYRULE_FIELD_EASTERN_HILLLS_CENTER, 0, 0, 72, 56, 2568,
      2760, CND_0, LOCAL_BANK_1, BEANDEMO_03 }, // uses different flags due to CND_8
    { WORLD_EVENT_TYPE_BEANSTALK, 0, AREA_HYRULE_FIELD, ROOM_HYRULE_FIELD_WESTERN_WOODS_SOUTH, 0, 0, 56, 56, 1064, 3016,
      CND_0, LOCAL_BANK_1, BEANDEMO_04 }, // uses different flags due to CND_9
#endif
    { WORLD_EVENT_TYPE_11, 0, AREA_CASTOR_WILDS, ROOM_CASTOR_WILDS_MAIN, 0, 48, 88, 152, 88, 1832, CND_0, 0, 0 },
    { WORLD_EVENT_TYPE_11, 1, AREA_CASTOR_WILDS, ROOM_CASTOR_WILDS_MAIN, 0, 160, 40, 232, 40, 1912, CND_0, 0, 0 },
    { WORLD_EVENT_TYPE_11, 2, AREA_CASTOR_WILDS, ROOM_CASTOR_WILDS_MAIN, 96, 664, 200, 776, 200, 2456, CND_0, 0, 0 },
#ifdef DEMO_JP
    // same as USA
    { WORLD_EVENT_TYPE_12, 0, AREA_HYRULE_TOWN, ROOM_HYRULE_TOWN_MAIN, 624, 784, 760, 952, 2184, 2360, CND_1,
      LOCAL_BANK_2, 208 }, // TODO
    { WORLD_EVENT_TYPE_13, 0, AREA_HOUSE_INTERIORS_4, ROOM_HOUSE_INTERIORS_4_CARPENTER, 0, 32, 120, 112, 1560, 1944,
      CND_1, LOCAL_BANK_2, 207 }, // TODO
#else
    { WORLD_EVENT_TYPE_12, 0, AREA_HYRULE_TOWN, ROOM_HYRULE_TOWN_MAIN, 624, 784, 760, 952, 2184, 2360, CND_0, 0, 0 },
    { WORLD_EVENT_TYPE_13, 0, AREA_HOUSE_INTERIORS_4, ROOM_HOUSE_INTERIORS_4_CARPENTER, 0, 32, 120, 112, 1560, 1944,
      CND_0, 0, 0 },
#endif
    { WORLD_EVENT_TYPE_14, 0, AREA_HYRULE_TOWN, ROOM_HYRULE_TOWN_MAIN, 768, 736, 904, 824, 2392, 2344, CND_0, 0, 0 },
    { WORLD_EVENT_TYPE_15, 0, AREA_ROYAL_VALLEY, ROOM_ROYAL_VALLEY_MAIN, 240, 96, 392, 136, 1400, 360, CND_0,
      LOCAL_BANK_1, HAKA_BOSEKI_00 }, // uses different flags due to CND_10
    { WORLD_EVENT_TYPE_16, 0, AREA_HYRULE_TOWN, ROOM_HYRULE_TOWN_MAIN, 768, 160, 736, 232, 2040, 2040, CND_0, 0, 0 },

    { WORLD_EVENT_TYPE_17, 0, AREA_HYRULE_FIELD, ROOM_HYRULE_FIELD_LON_LON_RANCH, 0, 800, 136, 856, 2624, 2056, CND_0,
      0, 0 },
    { WORLD_EVENT_TYPE_18, 1, AREA_GORON_CAVE, ROOM_GORON_CAVE_MAIN, 0, 464, 120, 440, 2632, 2056, CND_0, 0, 0 },
    { WORLD_EVENT_TYPE_18, 2, AREA_GORON_CAVE, ROOM_GORON_CAVE_MAIN, 0, 288, 120, 280, 2632, 2056, CND_0, 0, 0 },
    { WORLD_EVENT_TYPE_18, 3, AREA_GORON_CAVE, ROOM_GORON_CAVE_MAIN, 0, 288, 120, 280, 2632, 2056, CND_0, 0, 0 },
    { WORLD_EVENT_TYPE_18, 4, AREA_GORON_CAVE, ROOM_GORON_CAVE_MAIN, 0, 144, 120, 136, 2632, 2056, CND_0, 0, 0 },
    { WORLD_EVENT_TYPE_18, 5, AREA_GORON_CAVE, ROOM_GORON_CAVE_MAIN, 0, 144, 120, 136, 2632, 2056, CND_0, 0, 0 },
#else
    { WORLD_EVENT_TYPE_4, 0, AREA_HYRULE_FIELD, ROOM_HYRULE_FIELD_TRILBY_HIGHLANDS, 112, 160, 264, 264, 1272, 1432,
      CND_1, LOCAL_BANK_4, KS_B01 },
    { WORLD_EVENT_TYPE_4, 0, AREA_LAKE_HYLIA, ROOM_LAKE_HYLIA_MAIN, 352, 400, 488, 520, 3704, 1688, CND_1, LOCAL_BANK_3,
      MOGURA_01_T0 },
    { WORLD_EVENT_TYPE_4, 0, AREA_VEIL_FALLS, ROOM_VEIL_FALLS_MAIN, 160, 576, 232, 664, 2728, 824, CND_1, LOCAL_BANK_3,
      MOGURA_41_T3 },
    { WORLD_EVENT_TYPE_5, 132, AREA_CASTLE_GARDEN, ROOM_CASTLE_GARDEN_MAIN, 656, 0, 776, 72, 2264, 264, CND_1,
      LOCAL_BANK_3, IZUMIGARE_00_H00 },
    { WORLD_EVENT_TYPE_5, 1, AREA_HYRULE_FIELD, ROOM_HYRULE_FIELD_LON_LON_RANCH, 384, 440, 504, 520, 3000, 1720, CND_1,
      LOCAL_BANK_4, SOUGEN_DOUKUTU_0F_T00 },
    { WORLD_EVENT_TYPE_5, 2, AREA_HYRULE_FIELD, ROOM_HYRULE_FIELD_SOUTH_HYRULE_FIELD, 0, 200, 88, 280, 1576, 2760,
      CND_1, LOCAL_BANK_4, KS_C37 },
    { WORLD_EVENT_TYPE_5, 3, AREA_HYRULE_FIELD, ROOM_HYRULE_FIELD_TRILBY_HIGHLANDS, 0, 600, 56, 680, 1064, 1880, CND_1,
      LOCAL_BANK_4, KS_C12 },
    { WORLD_EVENT_TYPE_5, 128, AREA_CASTLE_GARDEN, ROOM_CASTLE_GARDEN_MAIN, 128, 0, 232, 72, 1720, 264, CND_1,
      LOCAL_BANK_3, KS_C02 },
    { WORLD_EVENT_TYPE_6, 0, AREA_HYRULE_FIELD, ROOM_HYRULE_FIELD_WESTERN_WOODS_NORTH, 112, 224, 216, 296, 1240, 2488,
      CND_1, LOCAL_BANK_1, SOUGEN_08_T00 },
    { WORLD_EVENT_TYPE_6, 0, AREA_HYRULE_FIELD, ROOM_HYRULE_FIELD_WESTERN_WOODS_NORTH, 56, 32, 168, 88, 1192, 2280,
      CND_1, LOCAL_BANK_1, KS_C21 },
    { WORLD_EVENT_TYPE_6, 0, AREA_HYRULE_FIELD, ROOM_HYRULE_FIELD_WESTERN_WOODS_NORTH, 240, 448, 392, 552, 1416, 2744,
      CND_1, LOCAL_BANK_1, KS_C25 },
    { WORLD_EVENT_TYPE_6, 0, AREA_HYRULE_FIELD, ROOM_HYRULE_FIELD_WESTERN_WOODS_NORTH, 0, 464, 24, 568, 1048, 2760,
      CND_1, LOCAL_BANK_2, MHOUSE08_00 },
    { WORLD_EVENT_TYPE_7, 128, AREA_HYRULE_FIELD, ROOM_HYRULE_FIELD_NORTH_HYRULE_FIELD, 448, 224, 576, 296, 2072, 1016,
      CND_1, LOCAL_BANK_4, SOUGEN_DOUKUTU_00_T1 },
    { WORLD_EVENT_TYPE_7, 128, AREA_HYRULE_FIELD, ROOM_HYRULE_FIELD_NORTH_HYRULE_FIELD, 304, 304, 432, 392, 1928, 1112,
      CND_1, LOCAL_BANK_4, SOUGEN_DOUKUTU_00_T2 },
    { WORLD_EVENT_TYPE_7, 128, AREA_HYRULE_FIELD, ROOM_HYRULE_FIELD_NORTH_HYRULE_FIELD, 328, 224, 432, 296, 1928, 1016,
      CND_1, LOCAL_BANK_4, SOUGEN_DOUKUTU_00_T0 },
    { WORLD_EVENT_TYPE_7, 128, AREA_HYRULE_FIELD, ROOM_HYRULE_FIELD_NORTH_HYRULE_FIELD, 448, 328, 576, 392, 2072, 1112,
      CND_1, LOCAL_BANK_4, SOUGEN_DOUKUTU_00_T3 },
    { WORLD_EVENT_TYPE_7, 0, AREA_HYRULE_FIELD, ROOM_HYRULE_FIELD_WESTERN_WOODS_NORTH, 40, 408, 160, 488, 1160, 2648,
      CND_1, LOCAL_BANK_2, URO_19_H0 },
    { WORLD_EVENT_TYPE_7, 1, AREA_MINISH_WOODS, ROOM_MINISH_WOODS_MAIN, 408, 376, 528, 456, 3496, 2600, CND_1,
      LOCAL_BANK_4, KS_B06 },
    { WORLD_EVENT_TYPE_7, 2, AREA_HYRULE_FIELD, ROOM_HYRULE_FIELD_NORTH_HYRULE_FIELD, 632, 232, 752, 312, 2248, 1032,
      CND_1, LOCAL_BANK_4, KS_B12 },
    { WORLD_EVENT_TYPE_7, 3, AREA_HYRULE_FIELD, ROOM_HYRULE_FIELD_SOUTH_HYRULE_FIELD, 768, 472, 928, 552, 2424, 3032,
      CND_1, LOCAL_BANK_2, URO_12_H0 },
    { WORLD_EVENT_TYPE_8, 0, AREA_RUINS, ROOM_RUINS_TEKTITES, 0, 0, 200, 88, 440, 2936, CND_1, LOCAL_BANK_2,
      KOBITOANA_0C_T0 },
    { WORLD_EVENT_TYPE_8, 0, AREA_MINISH_WOODS, ROOM_MINISH_WOODS_MAIN, 496, 848, 536, 968, 3512, 3128, CND_1,
      LOCAL_BANK_2, KOBITOANA_08_T0 },
    { WORLD_EVENT_TYPE_8, 0, AREA_CASTOR_WILDS, ROOM_CASTOR_WILDS_MAIN, 0, 16, 24, 88, 24, 1768, CND_1, LOCAL_BANK_2,
      KOBITOANA_0D_T0 },
    { WORLD_EVENT_TYPE_8, 0, AREA_LAKE_HYLIA, ROOM_LAKE_HYLIA_MAIN, 48, 424, 152, 520, 3368, 1720, CND_1, LOCAL_BANK_2,
      KS_A09 },
    { WORLD_EVENT_TYPE_9, 0, AREA_VEIL_FALLS, ROOM_VEIL_FALLS_MAIN, 0, 0, 56, 40, 2552, 232, CND_1, LOCAL_BANK_4,
      SUIGEN_DOUKUTU_09_H00 },
    { WORLD_EVENT_TYPE_9, 1, AREA_HYRULE_TOWN, ROOM_HYRULE_TOWN_MAIN, 112, 304, 240, 392, 1736, 1912, CND_1,
      LOCAL_BANK_4, SOUGEN_DOUKUTU_0B_T0 },
    { WORLD_EVENT_TYPE_25, 0, AREA_CASTOR_WILDS, ROOM_CASTOR_WILDS_MAIN, 768, 0, 920, 56, 920, 1752, CND_2, 0,
      ITEM_SKILL_FAST_SPIN },
    { WORLD_EVENT_TYPE_25, 1, AREA_HYRULE_FIELD, ROOM_HYRULE_FIELD_NORTH_HYRULE_FIELD, 80, 400, 200, 488, 1688, 1208,
      CND_2, 0, ITEM_SKILL_LONG_SPIN },
    { WORLD_EVENT_TYPE_25, 2, AREA_VEIL_FALLS, ROOM_VEIL_FALLS_MAIN, 128, 752, 248, 840, 2744, 1032, CND_2, 0,
      ITEM_SKILL_FAST_SPLIT },
    { WORLD_EVENT_TYPE_BEANSTALK, 0, AREA_MT_CRENEL, ROOM_MT_CRENEL_TOP, 0, 0, 152, 40, 152, 40, CND_5, LOCAL_BANK_1,
      BEANDEMO_00 }, // uses different flags due to CND_5
    { WORLD_EVENT_TYPE_BEANSTALK, 0, AREA_LAKE_HYLIA, ROOM_LAKE_HYLIA_BEANSTALK, 432, 0, 552, 88, 3528, 1096, CND_6,
      LOCAL_BANK_1, BEANDEMO_01 }, // uses different flags due to CND_6
    { WORLD_EVENT_TYPE_BEANSTALK, 0, AREA_RUINS, ROOM_RUINS_BEANSTALK, 0, 0, 72, 72, 312, 2712, CND_7, LOCAL_BANK_1,
      BEANDEMO_02 }, // uses different flags due to CND_7
    { WORLD_EVENT_TYPE_BEANSTALK, 0, AREA_HYRULE_FIELD, ROOM_HYRULE_FIELD_EASTERN_HILLLS_CENTER, 0, 0, 72, 56, 2568,
      2760, CND_8, LOCAL_BANK_1, BEANDEMO_03 }, // uses different flags due to CND_8
    { WORLD_EVENT_TYPE_BEANSTALK, 0, AREA_HYRULE_FIELD, ROOM_HYRULE_FIELD_WESTERN_WOODS_SOUTH, 0, 0, 56, 56, 1064, 3016,
      CND_9, LOCAL_BANK_1, BEANDEMO_04 }, // uses different flags due to CND_9
    { WORLD_EVENT_TYPE_11, 0, AREA_CASTOR_WILDS, ROOM_CASTOR_WILDS_MAIN, 0, 48, 88, 152, 88, 1832, CND_1, LOCAL_BANK_2,
      KOBITOANA_09_T0 },
    { WORLD_EVENT_TYPE_11, 1, AREA_CASTOR_WILDS, ROOM_CASTOR_WILDS_MAIN, 0, 160, 40, 232, 40, 1912, CND_1, LOCAL_BANK_2,
      KOBITOANA_0A_T0 },
    { WORLD_EVENT_TYPE_11, 2, AREA_CASTOR_WILDS, ROOM_CASTOR_WILDS_MAIN, 96, 664, 200, 776, 200, 2456, CND_1,
      LOCAL_BANK_2, KOBITOANA_0B_T0 },
    { WORLD_EVENT_TYPE_12, 0, AREA_HYRULE_TOWN, ROOM_HYRULE_TOWN_MAIN, 624, 784, 760, 952, 2184, 2360, CND_1,
      LOCAL_BANK_2, KS_A18 },
    { WORLD_EVENT_TYPE_13, 0, AREA_HOUSE_INTERIORS_4, ROOM_HOUSE_INTERIORS_4_CARPENTER, 0, 32, 120, 112, 1560, 1944,
      CND_1, LOCAL_BANK_2, KS_A02 },
    { WORLD_EVENT_TYPE_14, 0, AREA_HYRULE_TOWN, ROOM_HYRULE_TOWN_MAIN, 768, 736, 904, 824, 2392, 2344, CND_1,
      LOCAL_BANK_2, KS_B07 },
    { WORLD_EVENT_TYPE_15, 0, AREA_ROYAL_VALLEY, ROOM_ROYAL_VALLEY_MAIN, 240, 96, 392, 136, 1400, 360, CND_10,
      LOCAL_BANK_1, HAKA_BOSEKI_00 }, // uses different flags due to CND_10
    { WORLD_EVENT_TYPE_16, 0, AREA_HYRULE_TOWN, ROOM_HYRULE_TOWN_MAIN, 768, 160, 736, 232, 2040, 2040, CND_1,
      LOCAL_BANK_1, KS_B18 },
    { WORLD_EVENT_TYPE_17, 0, AREA_HYRULE_FIELD, ROOM_HYRULE_FIELD_LON_LON_RANCH, 0, 800, 136, 856, 2624, 2056, CND_1,
      LOCAL_BANK_4, GORON_DOUKUTU_01_T0 },
    { WORLD_EVENT_TYPE_18, 1, AREA_GORON_CAVE, ROOM_GORON_CAVE_MAIN, 0, 464, 120, 440, 2632, 2056, CND_1, LOCAL_BANK_4,
      GORON_DOUKUTU_01_T0 },
    { WORLD_EVENT_TYPE_18, 2, AREA_GORON_CAVE, ROOM_GORON_CAVE_MAIN, 0, 288, 120, 280, 2632, 2056, CND_1, LOCAL_BANK_4,
      GORON_DOUKUTU_01_T0 },
    { WORLD_EVENT_TYPE_18, 3, AREA_GORON_CAVE, ROOM_GORON_CAVE_MAIN, 0, 288, 120, 280, 2632, 2056, CND_1, LOCAL_BANK_4,
      GORON_DOUKUTU_01_T0 },
    { WORLD_EVENT_TYPE_18, 4, AREA_GORON_CAVE, ROOM_GORON_CAVE_MAIN, 0, 144, 120, 136, 2632, 2056, CND_1, LOCAL_BANK_4,
      GORON_DOUKUTU_01_T0 },
    { WORLD_EVENT_TYPE_18, 5, AREA_GORON_CAVE, ROOM_GORON_CAVE_MAIN, 0, 144, 120, 136, 2632, 2056, CND_1, LOCAL_BANK_4,
      GORON_DOUKUTU_01_T0 },
#endif
    { WORLD_EVENT_TYPE_19, 0, AREA_VEIL_FALLS_TOP, ROOM_VEIL_FALLS_TOP_0, 192, 0, 320, 104, 0, 0, CND_0, 0, 0 },
#if defined(EU) || defined(JP) || defined(DEMO_JP)
    { WORLD_EVENT_TYPE_20, 0, AREA_TREE_INTERIORS, ROOM_TREE_INTERIORS_WITCH_HUT, 0, 0, 120, 56, 3656, 2248, CND_0, 0,
      0 },
    { WORLD_EVENT_TYPE_21, 0, AREA_HOUSE_INTERIORS_3, ROOM_HOUSE_INTERIORS_3_BORLOV_ENTRANCE, 0, 0, 120, 72, 2152, 2152,
      CND_0, 0, 0 },
    { WORLD_EVENT_TYPE_22, 0, AREA_HOUSE_INTERIORS_1, ROOM_HOUSE_INTERIORS_1_POST_OFFICE, 0, 0, 72, 56, 1560, 1704,
      CND_0, 0, 0 },
    { WORLD_EVENT_TYPE_23, 0, AREA_MINISH_HOUSE_INTERIORS, ROOM_MINISH_HOUSE_INTERIORS_MINISH_WOODS_BOMB, 0, 0, 120, 88,
      3288, 2952, CND_0, 0, 0 },
#ifdef DEMO_JP
    { WORLD_EVENT_TYPE_24, 0, AREA_HYRULE_FIELD, ROOM_HYRULE_FIELD_SOUTH_HYRULE_FIELD, 464, 176, 584, 264, 2072, 2744,
      CND_1, LOCAL_BANK_1, 252 }, // TODO
#else
    { WORLD_EVENT_TYPE_24, 0, AREA_HYRULE_FIELD, ROOM_HYRULE_FIELD_SOUTH_HYRULE_FIELD, 464, 176, 584, 264, 2072, 2744,
      CND_0, 0, 0 },
#endif
#else
    { WORLD_EVENT_TYPE_20, 0, AREA_TREE_INTERIORS, ROOM_TREE_INTERIORS_WITCH_HUT, 0, 0, 120, 56, 3656, 2248, CND_2, 0,
      ITEM_BOTTLE_RED_POTION },
    { WORLD_EVENT_TYPE_21, 0, AREA_HOUSE_INTERIORS_3, ROOM_HOUSE_INTERIORS_3_BORLOV_ENTRANCE, 0, 0, 120, 72, 2152, 2152,
      CND_1, LOCAL_BANK_2, KS_B16 },
    { WORLD_EVENT_TYPE_22, 0, AREA_HOUSE_INTERIORS_1, ROOM_HOUSE_INTERIORS_1_POST_OFFICE, 0, 0, 72, 56, 1560, 1704,
      CND_1, LOCAL_BANK_2, BILL01_TESSIN_8 },
    { WORLD_EVENT_TYPE_23, 0, AREA_MINISH_HOUSE_INTERIORS, ROOM_MINISH_HOUSE_INTERIORS_MINISH_WOODS_BOMB, 0, 0, 120, 88,
      3288, 2952, CND_1, LOCAL_BANK_2, KHOUSE26_REMOCON },
    { WORLD_EVENT_TYPE_24, 0, AREA_HYRULE_FIELD, ROOM_HYRULE_FIELD_SOUTH_HYRULE_FIELD, 464, 176, 584, 264, 2072, 2744,
      CND_1, LOCAL_BANK_1, KS_A06 },
#endif
    { WORLD_EVENT_TYPE_0, 0, 0, 0, 0, 0, 0, 0, 0, 0, CND_0, 0, 0 },
    { WORLD_EVENT_TYPE_0, 0, 0, 0, 0, 0, 0, 0, 0, 0, CND_0, 0, 0 },
    { WORLD_EVENT_TYPE_0, 0, 0, 0, 0, 0, 0, 0, 0, 0, CND_0, 0, 0 },
    { WORLD_EVENT_TYPE_0, 0, 0, 0, 0, 0, 0, 0, 0, 0, CND_0, 0, 0 },
    { WORLD_EVENT_TYPE_0, 0, 0, 0, 0, 0, 0, 0, 0, 0, CND_0, 0, 0 },
};

// kinstone data

// const TileEntity gUnk_080FEAC8[] = {
//     { NONE, 0, 0, 0, 0x0, 0, 0 },
//     { NONE, 0, 0, 0, 0x0, 0, 0 },
//     { NONE, 0, 0, 0, 0x0, 0, 0 },
//     { NONE, 0, 0, 0, 0x0, 0, 0 },
//     { NONE, 0, 0, 0, 0x0, 0, 0 },
//     { NONE, 0, 0, 0, 0x0, 0, 0 },
//     { NONE, 0, 0, 0, 0x0, 0, 0 },
//     { NONE, 0, 0, 0, 0x0, 0, 0 },
//     { NONE, 0, 0, 0, 0x0, 0, 0 },
//     { NONE, 0, 0, 0, 0x0, 0, 0 },
//     { SMALL_CHEST, 180, 30, 0, 0x0, 0, 0 },
//     { SMALL_CHEST, 166, 92, 113, 0x0, 0, 0 },
//     { SMALL_CHEST, 167, 92, 114, 0x0, 0, 0 },
//     { SMALL_CHEST, 168, 92, 110, 0x0, 0, 0 },
//     { SMALL_CHEST, 181, 92, 114, 0x0, 0, 0 },
//     { SMALL_CHEST, 169, 92, 112, 0x0, 0, 0 },
//     { SMALL_CHEST, 170, 89, 0, 0x0, 0, 0 },
//     { SMALL_CHEST, 171, 63, 200, 0x0, 0, 0 },
//     { SMALL_CHEST, 172, 92, 113, 0x0, 0, 0 },
//     { SMALL_CHEST, 182, 92, 114, 0x0, 0, 0 },
//     { SMALL_CHEST, 183, 101, 0, 0x0, 0, 0 },
//     { SMALL_CHEST, 184, 92, 110, 0x0, 0, 0 },
//     { SMALL_CHEST, 185, 92, 111, 0x0, 0, 0 },
//     { SMALL_CHEST, 186, 92, 112, 0x0, 0, 0 },
//     { SMALL_CHEST, 187, 89, 0, 0x0, 0, 0 },
//     { SMALL_CHEST, 188, 63, 200, 0x0, 0, 0 },
//     { SMALL_CHEST, 189, 92, 112, 0x0, 0, 0 },
//     { SMALL_CHEST, 190, 92, 111, 0x0, 0, 0 },
//     { SMALL_CHEST, 191, 92, 110, 0x0, 0, 0 },
//     { SMALL_CHEST, 192, 63, 200, 0x0, 0, 0 },
//     { SMALL_CHEST, 193, 89, 0, 0x0, 0, 0 },
//     { SMALL_CHEST, 194, 92, 114, 0x0, 0, 0 },
//     { SMALL_CHEST, 195, 92, 113, 0x0, 0, 0 },
//     { SMALL_CHEST, 196, 89, 0, 0x0, 0, 0 },
//     { SMALL_CHEST, 197, 63, 200, 0x0, 0, 0 },
//     { NONE, 0, 0, 0, 0x0, 0, 0 },
// };

// const TileEntity gUnk_080FEAC8[] = {
//     { NONE, 0, 0, 0, 0x0, 0, 0 },
//     { NONE, 0, 0, 0, 0x0, 0, 0 },
//     { NONE, 0, 0, 0, 0x0, 0, 0 },
//     { NONE, 0, 0, 0, 0x0, 0, 0 },
//     { NONE, 0, 0, 0, 0x0, 0, 0 },
//     { NONE, 0, 0, 0, 0x0, 0, 0 },
//     { NONE, 0, 0, 0, 0x0, 0, 0 },
//     { NONE, 0, 0, 0, 0x0, 0, 0 },
//     { NONE, 0, 0, 0, 0x0, 0, 0 },
//     { NONE, 0, 0, 0, 0x0, 0, 0 },
//     { SMALL_CHEST, 3,178, 30, 0, 0x0, 0, 0 },
//     { SMALL_CHEST, 166, 92, 113, 0x0, 0, 0 },
//     { SMALL_CHEST, 167, 92, 114, 0x0, 0, 0 },
//     { SMALL_CHEST, 168, 92, 110, 0x0, 0, 0 },
//     { SMALL_CHEST, 179, 92, 114, 0x0, 0, 0 },
//     { SMALL_CHEST, 169, 92, 112, 0x0, 0, 0 },
//     { SMALL_CHEST, 170, 89, 0, 0x0, 0, 0 },
//     { SMALL_CHEST, 171, 63, 200, 0x0, 0, 0 },
//     { SMALL_CHEST, 172, 92, 113, 0x0, 0, 0 },
//     { SMALL_CHEST, 251, 92, 114, 0x0, 0, 0 },
//     { SMALL_CHEST, 180, 101, 0, 0x0, 0, 0 },
//     { SMALL_CHEST, 181, 92, 110, 0x0, 0, 0 },
//     { SMALL_CHEST, 182, 92, 111, 0x0, 0, 0 },
//     { SMALL_CHEST, 183, 92, 112, 0x0, 0, 0 },
//     { SMALL_CHEST, 184, 89, 0, 0x0, 0, 0 },
//     { SMALL_CHEST, 185, 63, 200, 0x0, 0, 0 },
//     { SMALL_CHEST, 186, 92, 112, 0x0, 0, 0 },
//     { SMALL_CHEST, 187, 92, 111, 0x0, 0, 0 },
//     { SMALL_CHEST, 188, 92, 110, 0x0, 0, 0 },
//     { SMALL_CHEST, 189, 63, 200, 0x0, 0, 0 },
//     { SMALL_CHEST, 190, 89, 0, 0x0, 0, 0 },
//     { SMALL_CHEST, 191, 92, 114, 0x0, 0, 0 },
//     { SMALL_CHEST, 192, 92, 113, 0x0, 0, 0 },
//     { SMALL_CHEST, 193, 89, 0, 0x0, 0, 0 },
//     { SMALL_CHEST, 194, 63, 200, 0x0, 0, 0 },
//     { NONE, 0, 0, 0, 0x0, 0, 0 },
// };
extern TileEntity gUnk_080FEAC8[]; // TODO differs jp, demo_jp, eu
extern const EntityData gUnk_080FEBE8[];
extern EntityData gUnk_080FECC8[];
extern EntityData gUnk_080FEC28[];
extern const EntityData gUnk_080FED18[];
extern EntityData gUnk_080FED58[];
// TODO need to find out what gRoomVars.entityRails[ptr->entity_idx] is.
extern const void* gLilypadRails[];
// gUnk_080FEDA4
// gUnk_080FEDDA
// gUnk_080FEDF8
extern const EntityData gUnk_080FEE18[];
extern const EntityData gUnk_080FEE38[];
extern const EntityData gUnk_080FEE48[];
extern const EntityData gUnk_080FEE58[]; // TODO differs jp, demo_jp, eu
extern EntityData gUnk_080FEE78[];
