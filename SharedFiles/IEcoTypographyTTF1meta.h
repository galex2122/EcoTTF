/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoTypographyTTF1meta
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoTypographyTTF1meta
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

#ifndef __I_ECO_TYPOGRAPHY_TTF_1_META_H__
#define __I_ECO_TYPOGRAPHY_TTF_1_META_H__

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

/* IEcoTypographyTTF1meta IID = {B74CA7B9-E8BE-4188-A4CB-66AA6E1144B0} */
#ifndef __IID_IEcoTypographyTTF1meta
static const UGUID IID_IEcoTypographyTTF1meta = { 0x01, 0x10, 0xB7, 0x4C, 0xA7, 0xB9, 0xE8, 0xBE, 0x41, 0x88, 0xA4, 0xCB, 0x66, 0xAA, 0x6E, 0x11, 0x44, 0xB0 };
#endif /* __IID_IEcoTypographyTTF1meta */

typedef struct IEcoTypographyTTF1metaVTbl {

    /* IEcoUnknown */
    int16_t (*QueryInterface )(/* in */ struct IEcoTypographyTTF1meta* me, /* in */ const UGUID* riid, /* out */ void **ppv);
    uint32_t (*AddRef )(/* in */ struct IEcoTypographyTTF1meta* me);
    uint32_t (*Release )(/* in */ struct IEcoTypographyTTF1meta* me);

    /* IEcoTypographyTTF1meta */
    ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR* (*get_Descriptor)(/* in */ struct IEcoTypographyTTF1meta* me);
    void (*set_Descriptor)(/* in */ struct IEcoTypographyTTF1meta* me, /* in */ ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR* descriptor);
    IEcoList1* (*get_TableDirectory)(/* in */ struct IEcoTypographyTTF1meta* me);
    void (*set_TableDirectory)(/* in */ struct IEcoTypographyTTF1meta* me, /* in */ IEcoList1* pIRecords);

} IEcoTypographyTTF1metaVTbl, *IEcoTypographyTTF1metaVTblPtr;

interface IEcoTypographyTTF1meta {
    struct IEcoTypographyTTF1metaVTbl *pVTbl;
} IEcoTypographyTTF1meta;

#endif /* __I_ECO_TYPOGRAPHY_TTF_1_META_H__ */
