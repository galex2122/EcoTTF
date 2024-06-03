/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoTypographyTTF1JSTF
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoTypographyTTF1JSTF
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

#ifndef __I_ECO_TYPOGRAPHY_TTF_1_JSTF_H__
#define __I_ECO_TYPOGRAPHY_TTF_1_JSTF_H__

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

/* IEcoTypographyTTF1JSTF IID = {5E386F90-651E-4634-AA7D-01B22686E5B0} */
#ifndef __IID_IEcoTypographyTTF1JSTF
static const UGUID IID_IEcoTypographyTTF1JSTF = { 0x01, 0x10, 0x5E, 0x38, 0x6F, 0x90, 0x65, 0x1E, 0x46, 0x34, 0xAA, 0x7D, 0x01, 0xB2, 0x26, 0x86, 0xE5, 0xB0 };
#endif /* __IID_IEcoTypographyTTF1JSTF */

typedef struct IEcoTypographyTTF1JSTFVTbl {

    /* IEcoUnknown */
    int16_t (*QueryInterface )(/* in */ struct IEcoTypographyTTF1JSTF* me, /* in */ const UGUID* riid, /* out */ void **ppv);
    uint32_t (*AddRef )(/* in */ struct IEcoTypographyTTF1JSTF* me);
    uint32_t (*Release )(/* in */ struct IEcoTypographyTTF1JSTF* me);

    /* IEcoTypographyTTF1JSTF */
    ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR* (*get_Descriptor)(/* in */ struct IEcoTypographyTTF1JSTF* me);
    void (*set_Descriptor)(/* in */ struct IEcoTypographyTTF1JSTF* me, /* in */ ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR* descriptor);
    IEcoList1* (*get_TableDirectory)(/* in */ struct IEcoTypographyTTF1JSTF* me);
    void (*set_TableDirectory)(/* in */ struct IEcoTypographyTTF1JSTF* me, /* in */ IEcoList1* pIRecords);

} IEcoTypographyTTF1JSTFVTbl, *IEcoTypographyTTF1JSTFVTblPtr;

interface IEcoTypographyTTF1JSTF {
    struct IEcoTypographyTTF1JSTFVTbl *pVTbl;
} IEcoTypographyTTF1JSTF;

#endif /* __I_ECO_TYPOGRAPHY_TTF_1_JSTF_H__ */
