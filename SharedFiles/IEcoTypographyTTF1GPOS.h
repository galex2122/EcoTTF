/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoTypographyTTF1GPOS
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoTypographyTTF1GPOS
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

#ifndef __I_ECO_TYPOGRAPHY_TTF_1_GPOS_H__
#define __I_ECO_TYPOGRAPHY_TTF_1_GPOS_H__

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

/* IEcoTypographyTTF1GPOS IID = {F820F85E-ED31-470E-8D67-0EFB7ABCB652} */
#ifndef __IID_IEcoTypographyTTF1GPOS
static const UGUID IID_IEcoTypographyTTF1GPOS = { 0x01, 0x10, 0xF8, 0x20, 0xF8, 0x5E, 0xED, 0x31, 0x47, 0x0E, 0x8D, 0x67, 0x0E, 0xFB, 0x7A, 0xBC, 0xB6, 0x52 };
#endif /* __IID_IEcoTypographyTTF1GPOS */

typedef struct IEcoTypographyTTF1GPOSVTbl {

    /* IEcoUnknown */
    int16_t (*QueryInterface )(/* in */ struct IEcoTypographyTTF1GPOS* me, /* in */ const UGUID* riid, /* out */ void **ppv);
    uint32_t (*AddRef )(/* in */ struct IEcoTypographyTTF1GPOS* me);
    uint32_t (*Release )(/* in */ struct IEcoTypographyTTF1GPOS* me);

    /* IEcoTypographyTTF1GPOS */
    ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR* (*get_Descriptor)(/* in */ struct IEcoTypographyTTF1GPOS* me);
    void (*set_Descriptor)(/* in */ struct IEcoTypographyTTF1GPOS* me, /* in */ ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR* descriptor);
    IEcoList1* (*get_TableDirectory)(/* in */ struct IEcoTypographyTTF1GPOS* me);
    void (*set_TableDirectory)(/* in */ struct IEcoTypographyTTF1GPOS* me, /* in */ IEcoList1* pIRecords);

} IEcoTypographyTTF1GPOSVTbl, *IEcoTypographyTTF1GPOSVTblPtr;

interface IEcoTypographyTTF1GPOS {
    struct IEcoTypographyTTF1GPOSVTbl *pVTbl;
} IEcoTypographyTTF1GPOS;

#endif /* __I_ECO_TYPOGRAPHY_TTF_1_GPOS_H__ */
