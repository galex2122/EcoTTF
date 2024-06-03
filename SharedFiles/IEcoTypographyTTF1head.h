/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoTypographyTTF1head
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoTypographyTTF1head
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

#ifndef __I_ECO_TYPOGRAPHY_TTF_1_HEAD_H__
#define __I_ECO_TYPOGRAPHY_TTF_1_HEAD_H__

#include "IEcoBase1.h"

typedef struct ECO_TRUE_TYPE_FONT_1_HEAD_DESCRIPTOR {
    uint16_t majorVersion;
    uint16_t minorVersion;
    uint32_t fontRevision;
    uint32_t checksumAdjustment;
    uint32_t magicNumber;
    uint16_t flags;
    uint16_t unitsPerEm;
    int64_t created;
    int64_t modified;
    int16_t xMin;
    int16_t yMin;
    int16_t xMax;
    int16_t yMax;
    uint16_t macStyle;
    uint16_t lowestRecPPEM;
    int16_t fontDirectionHint;
    int16_t indexToLocFormat;
    int16_t glyphDataFormat;
} ECO_TRUE_TYPE_FONT_1_HEAD_DESCRIPTOR;

/* IEcoTypographyTTF1head IID = {D0C5EC3F-03A5-4EE4-9588-978F2731E9E4} */
#ifndef __IID_IEcoTypographyTTF1head
static const UGUID IID_IEcoTypographyTTF1head = { 0x01, 0x10, 0xD0, 0xC5, 0xEC, 0x3F, 0x03, 0xA5, 0x4E, 0xE4, 0x95, 0x88, 0x97, 0x8F, 0x27, 0x31, 0xE9, 0xE4 };
#endif /* __IID_IEcoTypographyTTF1head */

typedef struct IEcoTypographyTTF1headVTbl {

    /* IEcoUnknown */
    int16_t (*QueryInterface )(/* in */ struct IEcoTypographyTTF1head* me, /* in */ const UGUID* riid, /* out */ void **ppv);
    uint32_t (*AddRef )(/* in */ struct IEcoTypographyTTF1head* me);
    uint32_t (*Release )(/* in */ struct IEcoTypographyTTF1head* me);

    /* IEcoTypographyTTF1head */
    ECO_TRUE_TYPE_FONT_1_HEAD_DESCRIPTOR* (*get_Descriptor)(/* in */ struct IEcoTypographyTTF1head* me);
    void (*set_Descriptor)(/* in */ struct IEcoTypographyTTF1head* me, /* in */ ECO_TRUE_TYPE_FONT_1_HEAD_DESCRIPTOR* descriptor);

} IEcoTypographyTTF1headVTbl, *IEcoTypographyTTF1headVTblPtr;

interface IEcoTypographyTTF1head {
    struct IEcoTypographyTTF1headVTbl *pVTbl;
} IEcoTypographyTTF1head;

#endif /* __I_ECO_TYPOGRAPHY_TTF_1_HEAD_H__ */
