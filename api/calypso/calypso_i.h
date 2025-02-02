#include "transit/navigo_i.h"
#include "transit/korrigo_i.h"
#include "transit/opus_i.h"
#include "transit/ravkav_i.h"
#include <furi.h>

#ifndef CALYPSO_I_H
#define CALYPSO_I_H

#define CALYPSO_CARD_DUMPS_COUNT 13

typedef enum {
    CALYPSO_CARD_MOBIB,
    CALYPSO_CARD_OPUS,
    CALYPSO_CARD_VIVA,
    CALYPSO_CARD_PASSPASS,
    CALYPSO_CARD_TAM,
    CALYPSO_CARD_TRANSPOLE,
    CALYPSO_CARD_OURA,
    CALYPSO_CARD_NAVIGO,
    CALYPSO_CARD_KORRIGO,
    CALYPSO_CARD_TISSEO,
    CALYPSO_CARD_ENVIBUS,
    CALYPSO_CARD_GIRONDE,
    CALYPSO_CARD_RAVKAV,
    CALYPSO_CARD_UNKNOWN
} CALYPSO_CARD_TYPE;

typedef struct {
    int folder;
    int app;
    int record;
    char* data;
} CalypsoAppDump;

typedef struct {
    NavigoCardData* navigo;
    KorrigoCardData* korrigo;
    OpusCardData* opus;
    RavKavCardData* ravkav;

    CalypsoAppDump dumps[CALYPSO_CARD_DUMPS_COUNT];
    int dumps_count;

    CALYPSO_CARD_TYPE card_type;
    unsigned int card_number;

    int contracts_count;
    int events_count;
    int special_events_count;

    int country_num;
    int network_num;
} CalypsoCardData;

typedef struct {
    CalypsoCardData* card;
    int page_id;
    // mutex
    FuriMutex* mutex;
} CalypsoContext;

#endif // CALYPSO_I_H
