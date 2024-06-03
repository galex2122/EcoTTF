/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoTypographyTTF1OS2
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoTypographyTTF1OS2
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

#ifndef __I_ECO_TYPOGRAPHY_TTF_1_OS2_H__
#define __I_ECO_TYPOGRAPHY_TTF_1_OS2_H__

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

/* IEcoTypographyTTF1OS2 IID = {1FDB4201-D47D-42E1-ABA7-8A410209AE1A} */
#ifndef __IID_IEcoTypographyTTF1OS2
static const UGUID IID_IEcoTypographyTTF1OS2 = { 0x01, 0x10, 0x1F, 0xDB, 0x42, 0x01, 0xD4, 0x7D, 0x42, 0xE1, 0xAB, 0xA7, 0x8A, 0x41, 0x02, 0x09, 0xAE, 0x1A };
#endif /* __IID_IEcoTypographyTTF1OS2 */

typedef struct IEcoTypographyTTF1OS2VTbl {

    /* IEcoUnknown */
    int16_t (*QueryInterface )(/* in */ struct IEcoTypographyTTF1OS2* me, /* in */ const UGUID* riid, /* out */ void **ppv);
    uint32_t (*AddRef )(/* in */ struct IEcoTypographyTTF1OS2* me);
    uint32_t (*Release )(/* in */ struct IEcoTypographyTTF1OS2* me);

    /* IEcoTypographyTTF1OS2 */
    ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR* (*get_Descriptor)(/* in */ struct IEcoTypographyTTF1OS2* me);
    void (*set_Descriptor)(/* in */ struct IEcoTypographyTTF1OS2* me, /* in */ ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR* descriptor);
    IEcoList1* (*get_TableDirectory)(/* in */ struct IEcoTypographyTTF1OS2* me);
    void (*set_TableDirectory)(/* in */ struct IEcoTypographyTTF1OS2* me, /* in */ IEcoList1* pIRecords);

} IEcoTypographyTTF1OS2VTbl, *IEcoTypographyTTF1OS2VTblPtr;

interface IEcoTypographyTTF1OS2 {
    struct IEcoTypographyTTF1OS2VTbl *pVTbl;
} IEcoTypographyTTF1OS2;

#endif /* __I_ECO_TYPOGRAPHY_TTF_1_OS2_H__ */
