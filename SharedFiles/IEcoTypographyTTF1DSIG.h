/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoTypographyTTF1DSIG
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoTypographyTTF1DSIG
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

#ifndef __I_ECO_TYPOGRAPHY_TTF_1_DSIG_H__
#define __I_ECO_TYPOGRAPHY_TTF_1_DSIG_H__

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

/* IEcoTypographyTTF1DSIG IID = {3916FB83-8A1D-4E1B-90E0-EAD3CFEFC3BF} */
#ifndef __IID_IEcoTypographyTTF1DSIG
static const UGUID IID_IEcoTypographyTTF1DSIG = { 0x01, 0x10, 0x39, 0x16, 0xFB, 0x83, 0x8A, 0x1D, 0x4E, 0x1B, 0x90, 0xE0, 0xEA, 0xD3, 0xCF, 0xEF, 0xC3, 0xBF };
#endif /* __IID_IEcoTypographyTTF1DSIG */

typedef struct IEcoTypographyTTF1DSIGVTbl {

    /* IEcoUnknown */
    int16_t (*QueryInterface )(/* in */ struct IEcoTypographyTTF1DSIG* me, /* in */ const UGUID* riid, /* out */ void **ppv);
    uint32_t (*AddRef )(/* in */ struct IEcoTypographyTTF1DSIG* me);
    uint32_t (*Release )(/* in */ struct IEcoTypographyTTF1DSIG* me);

    /* IEcoTypographyTTF1DSIG */
    ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR* (*get_Descriptor)(/* in */ struct IEcoTypographyTTF1DSIG* me);
    void (*set_Descriptor)(/* in */ struct IEcoTypographyTTF1DSIG* me, /* in */ ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR* descriptor);
    IEcoList1* (*get_TableDirectory)(/* in */ struct IEcoTypographyTTF1DSIG* me);
    void (*set_TableDirectory)(/* in */ struct IEcoTypographyTTF1DSIG* me, /* in */ IEcoList1* pIRecords);

} IEcoTypographyTTF1DSIGVTbl, *IEcoTypographyTTF1DSIGVTblPtr;

interface IEcoTypographyTTF1DSIG {
    struct IEcoTypographyTTF1DSIGVTbl *pVTbl;
} IEcoTypographyTTF1DSIG;

#endif /* __I_ECO_TYPOGRAPHY_TTF_1_DSIG_H__ */
