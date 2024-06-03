/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoTypographyTTF1GSUB
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoTypographyTTF1GSUB
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

#ifndef __I_ECO_TYPOGRAPHY_TTF_1_GSUB_H__
#define __I_ECO_TYPOGRAPHY_TTF_1_GSUB_H__

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

/* IEcoTypographyTTF1GSUB IID = {03E7BD12-52CC-4881-A64A-D6BBF0ABEA8B} */
#ifndef __IID_IEcoTypographyTTF1GSUB
static const UGUID IID_IEcoTypographyTTF1GSUB = { 0x01, 0x10, 0x03, 0xE7, 0xBD, 0x12, 0x52, 0xCC, 0x48, 0x81, 0xA6, 0x4A, 0xD6, 0xBB, 0xF0, 0xAB, 0xEA, 0x8B };
#endif /* __IID_IEcoTypographyTTF1GSUB */

typedef struct IEcoTypographyTTF1GSUBVTbl {

    /* IEcoUnknown */
    int16_t (*QueryInterface )(/* in */ struct IEcoTypographyTTF1GSUB* me, /* in */ const UGUID* riid, /* out */ void **ppv);
    uint32_t (*AddRef )(/* in */ struct IEcoTypographyTTF1GSUB* me);
    uint32_t (*Release )(/* in */ struct IEcoTypographyTTF1GSUB* me);

    /* IEcoTypographyTTF1GSUB */
    ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR* (*get_Descriptor)(/* in */ struct IEcoTypographyTTF1GSUB* me);
    void (*set_Descriptor)(/* in */ struct IEcoTypographyTTF1GSUB* me, /* in */ ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR* descriptor);
    IEcoList1* (*get_TableDirectory)(/* in */ struct IEcoTypographyTTF1GSUB* me);
    void (*set_TableDirectory)(/* in */ struct IEcoTypographyTTF1GSUB* me, /* in */ IEcoList1* pIRecords);

} IEcoTypographyTTF1GSUBVTbl, *IEcoTypographyTTF1GSUBVTblPtr;

interface IEcoTypographyTTF1GSUB {
    struct IEcoTypographyTTF1GSUBVTbl *pVTbl;
} IEcoTypographyTTF1GSUB;

#endif /* __I_ECO_TYPOGRAPHY_TTF_1_GSUB_H__ */
