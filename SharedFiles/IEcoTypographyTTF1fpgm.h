/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoTypographyTTF1fpgm
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoTypographyTTF1fpgm
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

#ifndef __I_ECO_TYPOGRAPHY_TTF_1_FPGM_H__
#define __I_ECO_TYPOGRAPHY_TTF_1_FPGM_H__

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

/* IEcoTypographyTTF1fpgm IID = {092AEBBA-6731-4C22-BE61-F73275094F8A} */
#ifndef __IID_IEcoTypographyTTF1fpgm
static const UGUID IID_IEcoTypographyTTF1fpgm = { 0x01, 0x10, 0x09, 0x2A, 0xEB, 0xBA, 0x67, 0x31, 0x4C, 0x22, 0xBE, 0x61, 0xF7, 0x32, 0x75, 0x09, 0x4F, 0x8A };
#endif /* __IID_IEcoTypographyTTF1fpgm */

typedef struct IEcoTypographyTTF1fpgmVTbl {

    /* IEcoUnknown */
    int16_t (*QueryInterface )(/* in */ struct IEcoTypographyTTF1fpgm* me, /* in */ const UGUID* riid, /* out */ void **ppv);
    uint32_t (*AddRef )(/* in */ struct IEcoTypographyTTF1fpgm* me);
    uint32_t (*Release )(/* in */ struct IEcoTypographyTTF1fpgm* me);

    /* IEcoTypographyTTF1fpgm */
    ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR* (*get_Descriptor)(/* in */ struct IEcoTypographyTTF1fpgm* me);
    void (*set_Descriptor)(/* in */ struct IEcoTypographyTTF1fpgm* me, /* in */ ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR* descriptor);
    IEcoList1* (*get_TableDirectory)(/* in */ struct IEcoTypographyTTF1fpgm* me);
    void (*set_TableDirectory)(/* in */ struct IEcoTypographyTTF1fpgm* me, /* in */ IEcoList1* pIRecords);

} IEcoTypographyTTF1fpgmVTbl, *IEcoTypographyTTF1fpgmVTblPtr;

interface IEcoTypographyTTF1fpgm {
    struct IEcoTypographyTTF1fpgmVTbl *pVTbl;
} IEcoTypographyTTF1fpgm;

#endif /* __I_ECO_TYPOGRAPHY_TTF_1_FPGM_H__ */
