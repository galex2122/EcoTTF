/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoTypographyTTF1loca
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoTypographyTTF1loca
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

#ifndef __I_ECO_TYPOGRAPHY_TTF_1_LOCA_H__
#define __I_ECO_TYPOGRAPHY_TTF_1_LOCA_H__

#include "IEcoBase1.h"

#define ECO_TTF_1_LOCA_INDEX_TO_LOC_FORMAT_OFFSET16 0
#define ECO_TTF_1_LOCA_INDEX_TO_LOC_FORMAT_OFFSET32 1

/* IEcoTypographyTTF1loca IID = {5838C7AA-9E63-406A-BD6B-35B9C8DA4F79} */
#ifndef __IID_IEcoTypographyTTF1loca
static const UGUID IID_IEcoTypographyTTF1loca = { 0x01, 0x10, 0x58, 0x38, 0xC7, 0xAA, 0x9E, 0x63, 0x40, 0x6A, 0xBD, 0x6B, 0x35, 0xB9, 0xC8, 0xDA, 0x4F, 0x79 };
#endif /* __IID_IEcoTypographyTTF1loca */

typedef struct IEcoTypographyTTF1locaVTbl {

    /* IEcoUnknown */
    int16_t (*QueryInterface )(/* in */ struct IEcoTypographyTTF1loca* me, /* in */ const UGUID* riid, /* out */ void **ppv);
    uint32_t (*AddRef )(/* in */ struct IEcoTypographyTTF1loca* me);
    uint32_t (*Release )(/* in */ struct IEcoTypographyTTF1loca* me);

    /* IEcoTypographyTTF1loca */
    int16_t (*get_OffsetFormat)(/* in */ struct IEcoTypographyTTF1loca* me);
    int16_t (*set_OffsettFormat)(/* in */ struct IEcoTypographyTTF1loca* me, /* in */ int16_t version);
    uint16_t (*get_Offset16)(/* in */ struct IEcoTypographyTTF1loca* me, /* in */ uint16_t n);
    int16_t (*set_Offset16)(/* in */ struct IEcoTypographyTTF1loca* me, /* in */ uint16_t n, /* in */ uint16_t offset);
    uint32_t (*get_Offset32)(/* in */ struct IEcoTypographyTTF1loca* me, /* in */ uint16_t n);
    int16_t (*set_Offset32)(/* in */ struct IEcoTypographyTTF1loca* me, /* in */ uint16_t n, /* in */ uint32_t offset);
    uint16_t (*get_OffsetCount)(/* in */ struct IEcoTypographyTTF1loca* me);
    void (*set_TableData)(/* in */ struct IEcoTypographyTTF1loca* me, /* in */ byte_t* pData, /* in */ uint32_t length);
    byte_t* (*get_TableData)(/* in */ struct IEcoTypographyTTF1loca* me);
    uint32_t (*get_TableLength)(/* in */ struct IEcoTypographyTTF1loca* me);

} IEcoTypographyTTF1locaVTbl, *IEcoTypographyTTF1locaVTblPtr;

interface IEcoTypographyTTF1loca {
    struct IEcoTypographyTTF1locaVTbl *pVTbl;
} IEcoTypographyTTF1loca;

#endif /* __I_ECO_TYPOGRAPHY_TTF_1_LOCA_H__ */
