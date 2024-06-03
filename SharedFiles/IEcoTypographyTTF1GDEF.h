/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoTypographyTTF1GDEF
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoTypographyTTF1GDEF
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

#ifndef __I_ECO_TYPOGRAPHY_TTF_1_GDEF_H__
#define __I_ECO_TYPOGRAPHY_TTF_1_GDEF_H__

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

/* IEcoTypographyTTF1GDEF IID = {9FD269C4-A46A-428A-BD44-A450725AF32F} */
#ifndef __IID_IEcoTypographyTTF1GDEF
static const UGUID IID_IEcoTypographyTTF1GDEF = { 0x01, 0x10, 0x9F, 0xD2, 0x69, 0xC4, 0xA4, 0x6A, 0x42, 0x8A, 0xBD, 0x44, 0xA4, 0x50, 0x72, 0x5A, 0xF3, 0x2F };
#endif /* __IID_IEcoTypographyTTF1GDEF */

typedef struct IEcoTypographyTTF1GDEFVTbl {

    /* IEcoUnknown */
    int16_t (*QueryInterface )(/* in */ struct IEcoTypographyTTF1GDEF* me, /* in */ const UGUID* riid, /* out */ void **ppv);
    uint32_t (*AddRef )(/* in */ struct IEcoTypographyTTF1GDEF* me);
    uint32_t (*Release )(/* in */ struct IEcoTypographyTTF1GDEF* me);

    /* IEcoTypographyTTF1GDEF */
    ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR* (*get_Descriptor)(/* in */ struct IEcoTypographyTTF1GDEF* me);
    void (*set_Descriptor)(/* in */ struct IEcoTypographyTTF1GDEF* me, /* in */ ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR* descriptor);
    IEcoList1* (*get_TableDirectory)(/* in */ struct IEcoTypographyTTF1GDEF* me);
    void (*set_TableDirectory)(/* in */ struct IEcoTypographyTTF1GDEF* me, /* in */ IEcoList1* pIRecords);

} IEcoTypographyTTF1GDEFVTbl, *IEcoTypographyTTF1GDEFVTblPtr;

interface IEcoTypographyTTF1GDEF {
    struct IEcoTypographyTTF1GDEFVTbl *pVTbl;
} IEcoTypographyTTF1GDEF;

#endif /* __I_ECO_TYPOGRAPHY_TTF_1_GDEF_H__ */
