/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoTypographyTTF1TableRecord
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoTypographyTTF1TableRecord
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

#ifndef __I_ECO_TYPOGRAPHY_TTF_1_TABLE_RECORD_H__
#define __I_ECO_TYPOGRAPHY_TTF_1_TABLE_RECORD_H__

#include "IEcoBase1.h"
#include "IEcoList1.h"

typedef struct ECO_TRUE_TYPE_FONT_1_TABLE_RECORD_DESCRIPTOR {
    uint32_t tag;
    uint32_t checksum;
    uint32_t offset;
    uint32_t length;
} ECO_TRUE_TYPE_FONT_1_TABLE_RECORD_DESCRIPTOR;

/* IEcoTypographyTTF1TableRecord IID = {2F03C0F8-3E87-4D13-88AD-5EB4A91CCA6E} */
#ifndef __IID_IEcoTypographyTTF1TableRecord
static const UGUID IID_IEcoTypographyTTF1TableRecord = { 0x01, 0x10, 0x2F, 0x03, 0xC0, 0xF8, 0x3E, 0x87, 0x4D, 0x13, 0x88, 0xAD, 0x5E, 0xB4, 0xA9, 0x1C, 0xCA, 0x6E };
#endif /* __IID_IEcoTypographyTTF1TableRecord */

typedef struct IEcoTypographyTTF1TableRecordVTbl {

    /* IEcoUnknown */
    int16_t (*QueryInterface )(/* in */ struct IEcoTypographyTTF1TableRecord* me, /* in */ const UGUID* riid, /* out */ void **ppv);
    uint32_t (*AddRef )(/* in */ struct IEcoTypographyTTF1TableRecord* me);
    uint32_t (*Release )(/* in */ struct IEcoTypographyTTF1TableRecord* me);

    /* IEcoTypographyTTF1TableRecord */
    ECO_TRUE_TYPE_FONT_1_TABLE_RECORD_DESCRIPTOR* (*get_Descriptor)(/* in */ struct IEcoTypographyTTF1TableRecord* me);
    void (*set_Descriptor)(/* in */ struct IEcoTypographyTTF1TableRecord* me, /* in */ ECO_TRUE_TYPE_FONT_1_TABLE_RECORD_DESCRIPTOR* descriptor);
    IEcoUnknown* (*get_Table)(/* in */ struct IEcoTypographyTTF1TableRecord* me);
    void (*set_Table)(/* in */ struct IEcoTypographyTTF1TableRecord* me, /* in */ IEcoUnknown* pITable);

} IEcoTypographyTTF1TableRecordVTbl, *IEcoTypographyTTF1TableRecordVTblPtr;

interface IEcoTypographyTTF1TableRecord {
    struct IEcoTypographyTTF1TableRecordVTbl *pVTbl;
} IEcoTypographyTTF1TableRecord;

#endif /* __I_ECO_TYPOGRAPHY_TTF_1_TABLE_RECORD_H__ */
