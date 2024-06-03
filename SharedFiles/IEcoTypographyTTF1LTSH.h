/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoTypographyTTF1LTSH
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoTypographyTTF1LTSH
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

#ifndef __I_ECO_TYPOGRAPHY_TTF_1_LTSH_H__
#define __I_ECO_TYPOGRAPHY_TTF_1_LTSH_H__

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

/* IEcoTypographyTTF1LTSH IID = {09AE979E-DA09-4E1B-801E-3F260532A96B} */
#ifndef __IID_IEcoTypographyTTF1LTSH
static const UGUID IID_IEcoTypographyTTF1LTSH = { 0x01, 0x10, 0x09, 0xAE, 0x97, 0x9E, 0xDA, 0x09, 0x4E, 0x1B, 0x80, 0x1E, 0x3F, 0x26, 0x05, 0x32, 0xA9, 0x6B };
#endif /* __IID_IEcoTypographyTTF1LTSH */

typedef struct IEcoTypographyTTF1LTSHVTbl {

    /* IEcoUnknown */
    int16_t (*QueryInterface )(/* in */ struct IEcoTypographyTTF1LTSH* me, /* in */ const UGUID* riid, /* out */ void **ppv);
    uint32_t (*AddRef )(/* in */ struct IEcoTypographyTTF1LTSH* me);
    uint32_t (*Release )(/* in */ struct IEcoTypographyTTF1LTSH* me);

    /* IEcoTypographyTTF1LTSH */
    ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR* (*get_Descriptor)(/* in */ struct IEcoTypographyTTF1LTSH* me);
    void (*set_Descriptor)(/* in */ struct IEcoTypographyTTF1LTSH* me, /* in */ ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR* descriptor);
    IEcoList1* (*get_TableDirectory)(/* in */ struct IEcoTypographyTTF1LTSH* me);
    void (*set_TableDirectory)(/* in */ struct IEcoTypographyTTF1LTSH* me, /* in */ IEcoList1* pIRecords);

} IEcoTypographyTTF1LTSHVTbl, *IEcoTypographyTTF1LTSHVTblPtr;

interface IEcoTypographyTTF1LTSH {
    struct IEcoTypographyTTF1LTSHVTbl *pVTbl;
} IEcoTypographyTTF1LTSH;

#endif /* __I_ECO_TYPOGRAPHY_TTF_1_LTSH_H__ */
