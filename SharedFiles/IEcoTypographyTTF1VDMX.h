/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoTypographyTTF1VDMX
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoTypographyTTF1VDMX
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

#ifndef __I_ECO_TYPOGRAPHY_TTF_1_VDMX_H__
#define __I_ECO_TYPOGRAPHY_TTF_1_VDMX_H__

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

/* IEcoTypographyTTF1VDMX IID = {023DC955-1DD9-47A9-884D-BC3166BF0A29} */
#ifndef __IID_IEcoTypographyTTF1VDMX
static const UGUID IID_IEcoTypographyTTF1VDMX = { 0x01, 0x10, 0x02, 0x3D, 0xC9, 0x55, 0x1D, 0xD9, 0x47, 0xA9, 0x88, 0x4D, 0xBC, 0x31, 0x66, 0xBF, 0x0A, 0x29 };
#endif /* __IID_IEcoTypographyTTF1VDMX */

typedef struct IEcoTypographyTTF1VDMXVTbl {

    /* IEcoUnknown */
    int16_t (*QueryInterface )(/* in */ struct IEcoTypographyTTF1VDMX* me, /* in */ const UGUID* riid, /* out */ void **ppv);
    uint32_t (*AddRef )(/* in */ struct IEcoTypographyTTF1VDMX* me);
    uint32_t (*Release )(/* in */ struct IEcoTypographyTTF1VDMX* me);

    /* IEcoTypographyTTF1VDMX */
    ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR* (*get_Descriptor)(/* in */ struct IEcoTypographyTTF1VDMX* me);
    void (*set_Descriptor)(/* in */ struct IEcoTypographyTTF1VDMX* me, /* in */ ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR* descriptor);
    IEcoList1* (*get_TableDirectory)(/* in */ struct IEcoTypographyTTF1VDMX* me);
    void (*set_TableDirectory)(/* in */ struct IEcoTypographyTTF1VDMX* me, /* in */ IEcoList1* pIRecords);

} IEcoTypographyTTF1VDMXVTbl, *IEcoTypographyTTF1VDMXVTblPtr;

interface IEcoTypographyTTF1VDMX {
    struct IEcoTypographyTTF1VDMXVTbl *pVTbl;
} IEcoTypographyTTF1VDMX;

#endif /* __I_ECO_TYPOGRAPHY_TTF_1_VDMX_H__ */
