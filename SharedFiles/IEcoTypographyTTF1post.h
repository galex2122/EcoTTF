/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoTypographyTTF1post
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoTypographyTTF1post
 * </описание>
 *
 * <ссылка>
 *
 * </ссылка>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __I_ECO_TYPOGRAPHY_TTF_1_POST_H__
#define __I_ECO_TYPOGRAPHY_TTF_1_POST_H__

#include "IEcoBase1.h"

#include "IEcoList1.h"

typedef struct ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR {
    uint32_t sfntVersion;
    uint16_t numTables;
    uint16_t searchRange;
    uint16_t entrySelector;
    uint16_t rangeShift;
} ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR;

typedef struct ECO_TRUE_TYPE_FONT_1_TABLE_RECORD_DESCRIPTOR {
    uint32_t tag;
    uint32_t checksum;
    uint32_t offset;
    uint32_t length;
} ECO_TRUE_TYPE_FONT_1_TABLE_RECORD_DESCRIPTOR;

/* IEcoTypographyTTF1post IID = {64F7D13F-00B4-4B94-9F35-9E7DF3CB002C} */
#ifndef __IID_IEcoTypographyTTF1post
static const UGUID IID_IEcoTypographyTTF1post = { 0x01, 0x10, 0x64, 0xF7, 0xD1, 0x3F, 0x00, 0xB4, 0x4B, 0x94, 0x9F, 0x35, 0x9E, 0x7D, 0xF3, 0xCB, 0x00, 0x2C };
#endif /* __IID_IEcoTypographyTTF1post */

typedef struct IEcoTypographyTTF1postVTbl {

    /* IEcoUnknown */
    int16_t (*QueryInterface )(/* in */ struct IEcoTypographyTTF1post* me, /* in */ const UGUID* riid, /* out */ void **ppv);
    uint32_t (*AddRef )(/* in */ struct IEcoTypographyTTF1post* me);
    uint32_t (*Release )(/* in */ struct IEcoTypographyTTF1post* me);

    /* IEcoTypographyTTF1post */
    ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR* (*get_Descriptor)(/* in */ struct IEcoTypographyTTF1post* me);
    void (*set_Descriptor)(/* in */ struct IEcoTypographyTTF1post* me, /* in */ ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR* descriptor);
    IEcoList1* (*get_TableDirectory)(/* in */ struct IEcoTypographyTTF1post* me);
    void (*set_TableDirectory)(/* in */ struct IEcoTypographyTTF1post* me, /* in */ IEcoList1* pIRecords);

} IEcoTypographyTTF1postVTbl, *IEcoTypographyTTF1postVTblPtr;

interface IEcoTypographyTTF1post {
    struct IEcoTypographyTTF1postVTbl *pVTbl;
} IEcoTypographyTTF1post;

#endif /* __I_ECO_TYPOGRAPHY_TTF_1_POST_H__ */
