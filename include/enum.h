/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** enum
*/

#ifndef ENUM_H
    #define ENUM_H

enum game_sprites {
    SPR_SKIN,
    SPR_CLOTHES,
    SPR_HAIR,
    SPR_BG,
    SPR_FG,
    SPR_OBJ,
    BG_PLAYER_CREATOR,
    BG_FIGHT,
    SPR_BUTTON,
    TALK_BAR,
    SPR_MERLIN,
    SPR_KEVIN,
    SPR_POLLO,
    SPR_CHLOE,
    LIFE,
    ITEM,
    EPITAFF_TITLE,
    HTP_SPR,
    NB_SPRITE
};

enum scenes {
    INTRODUCTION,
    HOW_TO_PLAY,
    MAIN_MENU,
    SETTINGS_MENU,
    PLAYER_CREATOR_SCENE,
    GAME_SCENE,
    FIGHT_SCENE,
    PAUSE_SCENE,
    NB_SCENE
};

enum buttons {
    PLAY,
    SETTINGS,
    QUIT,
    CANCEL,
    CONFIRM,
    VOLUME_MUSIC_PLUS,
    VOLUME_MUSIC_LESS,
    VOLUME_SOUND_PLUS,
    VOLUME_SOUND_LESS,
    LOW_FPS,
    EPITECH_FPS,
    HIGH_FPS,
    SKIN_PLUS,
    SKIN_LESS,
    HAIR_LESS,
    HAIR_PLUS,
    CLOTHES_PLUS,
    CLOTHES_LESS,
    MENU_BUTTON,
    RESUME,
    FIGHT_BUTTON,
    HOW_TO_PLAY_BUTTON,
    NB_BUTTON
};

enum music {
    MAIN_MENU_MUSIC,
    PLAYER_CREATOR_MUSIC,
    EPITECH_MUSIC,
    KEVIN_QUEST_MUSIC,
    CHLOE_QUEST_MUSIC,
    POLO_QUEST_MUSIC,
    CORENTIN_QUEST_MUSIC,
    BATTLE_MUSIC,
    KEVIN_BATTLE_MUSIC,
    CHLOE_BATTLE_MUSIC,
    POLO_BATTLE_MUSIC,
    CORENTIN_BATTLE_MUSIC,
    NB_MUSIC
};

enum sound {
    SELECTED_BUTTON_SOUND,
    CLICKED_BUTTON_SOUND,
    QUEST_COMPLETED_SOUND,
    OOF,
    FIGHT_SOUND,
    NB_SOUND
};

enum direction_character {
    DOWN,
    LEFT,
    UP,
    RIGHT
};

enum step_character {
    STAND,
    STEP_LEFT,
    STEP_RIGHT
};

enum status_character {
    ORIENTATION,
    STEP,
    MEMSTEP,
    NB_STATUS
};

enum skin_character {
    SKIN,
    CLOTHES,
    HAIR,
    NB_SKIN
};

enum skin {
    SKIN_WHITE,
    SKIN_BLACK,
    SKIN_ARAB,
    SKIN_ASIAN,
    SKIN_NB
};

enum clothes {
    CLOTHES_RED,
    CLOTHES_BLUE,
    CLOTHES_GREEN,
    SUIT_BLACK,
    SUIT_BLUE,
    SUIT_PURPLE,
    CLOTHES_NB
};

enum hair {
    HAIR_SHORT_BROWN,
    HAIR_SHORT_RED,
    HAIR_SHORT_BLOND,
    HAIR_LOCK_BROWN,
    HAIR_LOCK_RED,
    HAIR_LOCK_BLOND,
    HAIR_PONY_BROWN,
    HAIR_PONY_RED,
    HAIR_PONY_BLOND,
    HAIR_PONY_LOCK_BROWN,
    HAIR_PONY_LOCK_RED,
    HAIR_PONY_LOCK_BLOND,
    BALD,
    HAIR_NB
};


enum font {
    MENU_FONT,
    DIALOGUE_FONT,
    NB_FONT
};

enum inv_slot {
    SLOT_ONE,
    SLOT_TWO,
    SLOT_THREE,
    SLOT_FOUR,
    SLOT_FIVE,
    SLOT_SIX,
    NB_SLOT
};

enum quest_info {
    QUEST_NAME,
    QUEST_DESCRIPTION,
    NB_QUEST_INFO
};

enum quest {
    DISCOVER_EPITECH,
    KEVIN_QUEST,
    CHLOE_QUEST,
    POLO_QUEST,
    CORENTIN_QUEST,
    FINISHED_QUEST,
    NB_QUEST
};

enum animations_intro {
    BG_INTRO,
    INCLINED_SQUARE,
    TRANSITION,
    NB_ANIMATIONS_INTRO
};

enum item {
    EPITECH_CARD,
    CHARGER,
    SOCK,
    CHAIR,
    KEBAB_BOX,
    BUENO,
    HEADSET,
    EVIAN,
    USB,
    MOUSE,
    PC,
    PEN,
    COCA,
    POISON,
    KEYBOARD,
    SMARTPHONE,
    KEY,
    TACOS,
    REDBULL,
    KFC,
    SANDWITCH,
    COIN,
    UTENSILS,
    PANCAKES,
    TRAM_CARD,
    NB_ITEM
};

enum npc {
    ALEXIS,
    ANTHONY,
    ANTOINE,
    ANTOINEZ,
    ARTHURD,
    ARTHURK,
    AUGUSTE,
    AUGUSTIN,
    AXEL,
    BANETTE,
    BAMPTISTEM,
    BENJAMIN,
    BILLERAY,
    CHAILLARD,
    CHAPAU,
    CHLOE,
    CLEMENTR,
    CLEMENTS,
    CORENTIN,
    DIMITRI,
    ELIA,
    ELRIC,
    EMILIEN,
    FELIX,
    FLORENT,
    FLORIANM,
    FLORIANS,
    FRED,
    GUILLAUME,
    GUILLAUMED,
    HELENA,
    HINDOWA,
    HOANGGIANG,
    HUGO,
    HUGOD,
    HUGOG,
    IBRAHIM,
    ISG_ONE,
    ISG_TWO,
    ISG_THREE,
    ISMAIL,
    JEANEPP,
    JEANFRANCOIS,
    JG,
    JONATHANN,
    JULIEN,
    KABEN,
    KAISER,
    KEVIN,
    KILIANP,
    KILIANS,
    KILIANT,
    LAURENT,
    LEOK,
    LEOS,
    LIENHART,
    LOIC,
    LOUISK,
    LOUISL,
    LOUISP,
    LUCAS,
    LUCASH,
    LUCASZ,
    LUCIEN,
    MARCHA,
    MARIN,
    MARIUS,
    MATHIEUH,
    MATTHIEUP,
    MATTHIEUR,
    MAXIME,
    MELANIE,
    PAUL,
    PAULD,
    POLLOMACK,
    QUENTINC,
    QUENTINH,
    QUENTINK,
    QUENTINT,
    REMY,
    ROMUALD,
    SAX_GUY,
    SEICHEPINE,
    TIMOTHEE,
    TOM,
    VALENTINA,
    VALENTINM,
    VICTORK,
    VICTORL,
    YANIS,
    YANN,
    YUANTAO,
    YVAN,
    OMAR,
    NB_NPC
};

enum htp_pages {
    PLAYER_CREATOR,
    GAME,
    FIGHT,
    MISC,
    NB_HTP_PAGES
};

#endif