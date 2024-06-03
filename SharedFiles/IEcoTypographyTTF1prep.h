/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoTypographyTTF1prep
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoTypographyTTF1prep
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

#ifndef __I_ECO_TYPOGRAPHY_TTF_1_PREP_H__
#define __I_ECO_TYPOGRAPHY_TTF_1_PREP_H__

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

/* IEcoTypographyTTF1prep IID = {318E37B6-4554-43DC-B694-692038384EFE} */
#ifndef __IID_IEcoTypographyTTF1prep
static const UGUID IID_IEcoTypographyTTF1prep = { 0x01, 0x10, 0x31, 0x8E, 0x37, 0xB6, 0x45, 0x54, 0x43, 0xDC, 0xB6, 0x94, 0x69, 0x20, 0x38, 0x38, 0x4E, 0xFE };
#endif /* __IID_IEcoTypographyTTF1prep */

typedef struct IEcoTypographyTTF1prepVTbl {

    /* IEcoUnknown */
    int16_t (*QueryInterface )(/* in */ struct IEcoTypographyTTF1prep* me, /* in */ const UGUID* riid, /* out */ void **ppv);
    uint32_t (*AddRef )(/* in */ struct IEcoTypographyTTF1prep* me);
    uint32_t (*Release )(/* in */ struct IEcoTypographyTTF1prep* me);

    /* IEcoTypographyTTF1prep */
    ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR* (*get_Descriptor)(/* in */ struct IEcoTypographyTTF1prep* me);
    void (*set_Descriptor)(/* in */ struct IEcoTypographyTTF1prep* me, /* in */ ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR* descriptor);
    IEcoList1* (*get_TableDirectory)(/* in */ struct IEcoTypographyTTF1prep* me);
    void (*set_TableDirectory)(/* in */ struct IEcoTypographyTTF1prep* me, /* in */ IEcoList1* pIRecords);

} IEcoTypographyTTF1prepVTbl, *IEcoTypographyTTF1prepVTblPtr;

interface IEcoTypographyTTF1prep {
    struct IEcoTypographyTTF1prepVTbl *pVTbl;
} IEcoTypographyTTF1prep;

#endif /* __I_ECO_TYPOGRAPHY_TTF_1_PREP_H__ */
