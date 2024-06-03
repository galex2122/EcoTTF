/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoTypographyTTF1cvt
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoTypographyTTF1cvt
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

#ifndef __I_ECO_TYPOGRAPHY_TTF_1_CVT_H__
#define __I_ECO_TYPOGRAPHY_TTF_1_CVT_H__

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

/* IEcoTypographyTTF1cvt IID = {CE5E5E70-94BA-424A-A570-C4F8750F495B} */
#ifndef __IID_IEcoTypographyTTF1cvt
static const UGUID IID_IEcoTypographyTTF1cvt = { 0x01, 0x10, 0xCE, 0x5E, 0x5E, 0x70, 0x94, 0xBA, 0x42, 0x4A, 0xA5, 0x70, 0xC4, 0xF8, 0x75, 0x0F, 0x49, 0x5B };
#endif /* __IID_IEcoTypographyTTF1cvt */

typedef struct IEcoTypographyTTF1cvtVTbl {

    /* IEcoUnknown */
    int16_t (*QueryInterface )(/* in */ struct IEcoTypographyTTF1cvt* me, /* in */ const UGUID* riid, /* out */ void **ppv);
    uint32_t (*AddRef )(/* in */ struct IEcoTypographyTTF1cvt* me);
    uint32_t (*Release )(/* in */ struct IEcoTypographyTTF1cvt* me);

    /* IEcoTypographyTTF1cvt */
    ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR* (*get_Descriptor)(/* in */ struct IEcoTypographyTTF1cvt* me);
    void (*set_Descriptor)(/* in */ struct IEcoTypographyTTF1cvt* me, /* in */ ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR* descriptor);
    IEcoList1* (*get_TableDirectory)(/* in */ struct IEcoTypographyTTF1cvt* me);
    void (*set_TableDirectory)(/* in */ struct IEcoTypographyTTF1cvt* me, /* in */ IEcoList1* pIRecords);

} IEcoTypographyTTF1cvtVTbl, *IEcoTypographyTTF1cvtVTblPtr;

interface IEcoTypographyTTF1cvt {
    struct IEcoTypographyTTF1cvtVTbl *pVTbl;
} IEcoTypographyTTF1cvt;

#endif /* __I_ECO_TYPOGRAPHY_TTF_1_CVT_H__ */
