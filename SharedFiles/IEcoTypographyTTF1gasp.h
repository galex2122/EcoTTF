/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoTypographyTTF1gasp
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoTypographyTTF1gasp
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

#ifndef __I_ECO_TYPOGRAPHY_TTF_1_GASP_H__
#define __I_ECO_TYPOGRAPHY_TTF_1_GASP_H__

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

/* IEcoTypographyTTF1gasp IID = {0EA04735-D988-4930-AD38-9042557E93EB} */
#ifndef __IID_IEcoTypographyTTF1gasp
static const UGUID IID_IEcoTypographyTTF1gasp = { 0x01, 0x10, 0x0E, 0xA0, 0x47, 0x35, 0xD9, 0x88, 0x49, 0x30, 0xAD, 0x38, 0x90, 0x42, 0x55, 0x7E, 0x93, 0xEB };
#endif /* __IID_IEcoTypographyTTF1gasp */

typedef struct IEcoTypographyTTF1gaspVTbl {

    /* IEcoUnknown */
    int16_t (*QueryInterface )(/* in */ struct IEcoTypographyTTF1gasp* me, /* in */ const UGUID* riid, /* out */ void **ppv);
    uint32_t (*AddRef )(/* in */ struct IEcoTypographyTTF1gasp* me);
    uint32_t (*Release )(/* in */ struct IEcoTypographyTTF1gasp* me);

    /* IEcoTypographyTTF1gasp */
    ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR* (*get_Descriptor)(/* in */ struct IEcoTypographyTTF1gasp* me);
    void (*set_Descriptor)(/* in */ struct IEcoTypographyTTF1gasp* me, /* in */ ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR* descriptor);
    IEcoList1* (*get_TableDirectory)(/* in */ struct IEcoTypographyTTF1gasp* me);
    void (*set_TableDirectory)(/* in */ struct IEcoTypographyTTF1gasp* me, /* in */ IEcoList1* pIRecords);

} IEcoTypographyTTF1gaspVTbl, *IEcoTypographyTTF1gaspVTblPtr;

interface IEcoTypographyTTF1gasp {
    struct IEcoTypographyTTF1gaspVTbl *pVTbl;
} IEcoTypographyTTF1gasp;

#endif /* __I_ECO_TYPOGRAPHY_TTF_1_GASP_H__ */
