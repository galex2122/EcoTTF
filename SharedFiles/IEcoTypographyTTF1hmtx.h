/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoTypographyTTF1hmtx
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoTypographyTTF1hmtx
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

#ifndef __I_ECO_TYPOGRAPHY_TTF_1_HMTX_H__
#define __I_ECO_TYPOGRAPHY_TTF_1_HMTX_H__

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

/* IEcoTypographyTTF1hmtx IID = {85F31049-D857-42D4-B298-D3023ABCB97D} */
#ifndef __IID_IEcoTypographyTTF1hmtx
static const UGUID IID_IEcoTypographyTTF1hmtx = { 0x01, 0x10, 0x85, 0xF3, 0x10, 0x49, 0xD8, 0x57, 0x42, 0xD4, 0xB2, 0x98, 0xD3, 0x02, 0x3A, 0xBC, 0xB9, 0x7D };
#endif /* __IID_IEcoTypographyTTF1hmtx */

typedef struct IEcoTypographyTTF1hmtxVTbl {

    /* IEcoUnknown */
    int16_t (*QueryInterface )(/* in */ struct IEcoTypographyTTF1hmtx* me, /* in */ const UGUID* riid, /* out */ void **ppv);
    uint32_t (*AddRef )(/* in */ struct IEcoTypographyTTF1hmtx* me);
    uint32_t (*Release )(/* in */ struct IEcoTypographyTTF1hmtx* me);

    /* IEcoTypographyTTF1hmtx */
    ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR* (*get_Descriptor)(/* in */ struct IEcoTypographyTTF1hmtx* me);
    void (*set_Descriptor)(/* in */ struct IEcoTypographyTTF1hmtx* me, /* in */ ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR* descriptor);
    IEcoList1* (*get_TableDirectory)(/* in */ struct IEcoTypographyTTF1hmtx* me);
    void (*set_TableDirectory)(/* in */ struct IEcoTypographyTTF1hmtx* me, /* in */ IEcoList1* pIRecords);

} IEcoTypographyTTF1hmtxVTbl, *IEcoTypographyTTF1hmtxVTblPtr;

interface IEcoTypographyTTF1hmtx {
    struct IEcoTypographyTTF1hmtxVTbl *pVTbl;
} IEcoTypographyTTF1hmtx;

#endif /* __I_ECO_TYPOGRAPHY_TTF_1_HMTX_H__ */
