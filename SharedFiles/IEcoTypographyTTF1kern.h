/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoTypographyTTF1kern
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoTypographyTTF1kern
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

#ifndef __I_ECO_TYPOGRAPHY_TTF_1_KERN_H__
#define __I_ECO_TYPOGRAPHY_TTF_1_KERN_H__

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

/* IEcoTypographyTTF1kern IID = {5E01D8D9-4C18-4342-8E5A-E4615DD76119} */
#ifndef __IID_IEcoTypographyTTF1kern
static const UGUID IID_IEcoTypographyTTF1kern = { 0x01, 0x10, 0x5E, 0x01, 0xD8, 0xD9, 0x4C, 0x18, 0x43, 0x42, 0x8E, 0x5A, 0xE4, 0x61, 0x5D, 0xD7, 0x61, 0x19 };
#endif /* __IID_IEcoTypographyTTF1kern */

typedef struct IEcoTypographyTTF1kernVTbl {

    /* IEcoUnknown */
    int16_t (*QueryInterface )(/* in */ struct IEcoTypographyTTF1kern* me, /* in */ const UGUID* riid, /* out */ void **ppv);
    uint32_t (*AddRef )(/* in */ struct IEcoTypographyTTF1kern* me);
    uint32_t (*Release )(/* in */ struct IEcoTypographyTTF1kern* me);

    /* IEcoTypographyTTF1kern */
    ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR* (*get_Descriptor)(/* in */ struct IEcoTypographyTTF1kern* me);
    void (*set_Descriptor)(/* in */ struct IEcoTypographyTTF1kern* me, /* in */ ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR* descriptor);
    IEcoList1* (*get_TableDirectory)(/* in */ struct IEcoTypographyTTF1kern* me);
    void (*set_TableDirectory)(/* in */ struct IEcoTypographyTTF1kern* me, /* in */ IEcoList1* pIRecords);

} IEcoTypographyTTF1kernVTbl, *IEcoTypographyTTF1kernVTblPtr;

interface IEcoTypographyTTF1kern {
    struct IEcoTypographyTTF1kernVTbl *pVTbl;
} IEcoTypographyTTF1kern;

#endif /* __I_ECO_TYPOGRAPHY_TTF_1_KERN_H__ */
