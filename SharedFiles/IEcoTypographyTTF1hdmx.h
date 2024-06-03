/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoTypographyTTF1hdmx
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoTypographyTTF1hdmx
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

#ifndef __I_ECO_TYPOGRAPHY_TTF_1_HDMX_H__
#define __I_ECO_TYPOGRAPHY_TTF_1_HDMX_H__

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

/* IEcoTypographyTTF1hdmx IID = {9830EE93-B2B3-438A-A54F-190D7582828C} */
#ifndef __IID_IEcoTypographyTTF1hdmx
static const UGUID IID_IEcoTypographyTTF1hdmx = { 0x01, 0x10, 0x98, 0x30, 0xEE, 0x93, 0xB2, 0xB3, 0x43, 0x8A, 0xA5, 0x4F, 0x19, 0x0D, 0x75, 0x82, 0x82, 0x8C };
#endif /* __IID_IEcoTypographyTTF1hdmx */

typedef struct IEcoTypographyTTF1hdmxVTbl {

    /* IEcoUnknown */
    int16_t (*QueryInterface )(/* in */ struct IEcoTypographyTTF1hdmx* me, /* in */ const UGUID* riid, /* out */ void **ppv);
    uint32_t (*AddRef )(/* in */ struct IEcoTypographyTTF1hdmx* me);
    uint32_t (*Release )(/* in */ struct IEcoTypographyTTF1hdmx* me);

    /* IEcoTypographyTTF1hdmx */
    ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR* (*get_Descriptor)(/* in */ struct IEcoTypographyTTF1hdmx* me);
    void (*set_Descriptor)(/* in */ struct IEcoTypographyTTF1hdmx* me, /* in */ ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR* descriptor);
    IEcoList1* (*get_TableDirectory)(/* in */ struct IEcoTypographyTTF1hdmx* me);
    void (*set_TableDirectory)(/* in */ struct IEcoTypographyTTF1hdmx* me, /* in */ IEcoList1* pIRecords);

} IEcoTypographyTTF1hdmxVTbl, *IEcoTypographyTTF1hdmxVTblPtr;

interface IEcoTypographyTTF1hdmx {
    struct IEcoTypographyTTF1hdmxVTbl *pVTbl;
} IEcoTypographyTTF1hdmx;

#endif /* __I_ECO_TYPOGRAPHY_TTF_1_HDMX_H__ */
