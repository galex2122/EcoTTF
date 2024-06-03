/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoTypographyTTF1name
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoTypographyTTF1name
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

#ifndef __I_ECO_TYPOGRAPHY_TTF_1_NAME_H__
#define __I_ECO_TYPOGRAPHY_TTF_1_NAME_H__

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

/* IEcoTypographyTTF1name IID = {25DAD2C0-D039-4CA5-B40A-003C13AADD1A} */
#ifndef __IID_IEcoTypographyTTF1name
static const UGUID IID_IEcoTypographyTTF1name = { 0x01, 0x10, 0x25, 0xDA, 0xD2, 0xC0, 0xD0, 0x39, 0x4C, 0xA5, 0xB4, 0x0A, 0x00, 0x3C, 0x13, 0xAA, 0xDD, 0x1A };
#endif /* __IID_IEcoTypographyTTF1name */

typedef struct IEcoTypographyTTF1nameVTbl {

    /* IEcoUnknown */
    int16_t (*QueryInterface )(/* in */ struct IEcoTypographyTTF1name* me, /* in */ const UGUID* riid, /* out */ void **ppv);
    uint32_t (*AddRef )(/* in */ struct IEcoTypographyTTF1name* me);
    uint32_t (*Release )(/* in */ struct IEcoTypographyTTF1name* me);

    /* IEcoTypographyTTF1name */
    ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR* (*get_Descriptor)(/* in */ struct IEcoTypographyTTF1name* me);
    void (*set_Descriptor)(/* in */ struct IEcoTypographyTTF1name* me, /* in */ ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR* descriptor);
    IEcoList1* (*get_TableDirectory)(/* in */ struct IEcoTypographyTTF1name* me);
    void (*set_TableDirectory)(/* in */ struct IEcoTypographyTTF1name* me, /* in */ IEcoList1* pIRecords);

} IEcoTypographyTTF1nameVTbl, *IEcoTypographyTTF1nameVTblPtr;

interface IEcoTypographyTTF1name {
    struct IEcoTypographyTTF1nameVTbl *pVTbl;
} IEcoTypographyTTF1name;

#endif /* __I_ECO_TYPOGRAPHY_TTF_1_NAME_H__ */
