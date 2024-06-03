/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoTypographyTTF1PCLT
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoTypographyTTF1PCLT
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

#ifndef __I_ECO_TYPOGRAPHY_TTF_1_PCLT_H__
#define __I_ECO_TYPOGRAPHY_TTF_1_PCLT_H__

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

/* IEcoTypographyTTF1PCLT IID = {BDA9E23C-D37A-4927-8A3A-CFDCCB308329} */
#ifndef __IID_IEcoTypographyTTF1PCLT
static const UGUID IID_IEcoTypographyTTF1PCLT = { 0x01, 0x10, 0xBD, 0xA9, 0xE2, 0x3C, 0xD3, 0x7A, 0x49, 0x27, 0x8A, 0x3A, 0xCF, 0xDC, 0xCB, 0x30, 0x83, 0x29 };
#endif /* __IID_IEcoTypographyTTF1PCLT */

typedef struct IEcoTypographyTTF1PCLTVTbl {

    /* IEcoUnknown */
    int16_t (*QueryInterface )(/* in */ struct IEcoTypographyTTF1PCLT* me, /* in */ const UGUID* riid, /* out */ void **ppv);
    uint32_t (*AddRef )(/* in */ struct IEcoTypographyTTF1PCLT* me);
    uint32_t (*Release )(/* in */ struct IEcoTypographyTTF1PCLT* me);

    /* IEcoTypographyTTF1PCLT */
    ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR* (*get_Descriptor)(/* in */ struct IEcoTypographyTTF1PCLT* me);
    void (*set_Descriptor)(/* in */ struct IEcoTypographyTTF1PCLT* me, /* in */ ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR* descriptor);
    IEcoList1* (*get_TableDirectory)(/* in */ struct IEcoTypographyTTF1PCLT* me);
    void (*set_TableDirectory)(/* in */ struct IEcoTypographyTTF1PCLT* me, /* in */ IEcoList1* pIRecords);

} IEcoTypographyTTF1PCLTVTbl, *IEcoTypographyTTF1PCLTVTblPtr;

interface IEcoTypographyTTF1PCLT {
    struct IEcoTypographyTTF1PCLTVTbl *pVTbl;
} IEcoTypographyTTF1PCLT;

#endif /* __I_ECO_TYPOGRAPHY_TTF_1_PCLT_H__ */
