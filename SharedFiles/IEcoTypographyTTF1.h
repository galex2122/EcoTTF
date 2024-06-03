/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoTypographyTTF1
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoTypographyTTF1
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

#ifndef __I_ECO_TYPOGRAPHY_TTF_1_H__
#define __I_ECO_TYPOGRAPHY_TTF_1_H__

#include "IEcoBase1.h"
#include "IEcoTypographyTTF1FontFile.h"
#include "IEcoTypographyTTF1TableRecord.h"
#include "IEcoTypographyTTF1head.h"
#include "IEcoTypographyTTF1cmap.h"
#include "IEcoTypographyTTF1glyf.h"
#include "IEcoTypographyTTF1maxp.h"
#include "IEcoTypographyTTF1loca.h"

/* IEcoTypographyTTF1 IID = {FC300438-926D-4270-B684-6AE055E3534A} */
#ifndef __IID_IEcoTypographyTTF1
static const UGUID IID_IEcoTypographyTTF1 = {0x01, 0x10, 0xFC, 0x30, 0x04, 0x38, 0x92, 0x6D, 0x42, 0x70, 0xB6, 0x84, 0x6A, 0xE0, 0x55, 0xE3, 0x53, 0x4A};
#endif /* __IID_IEcoTypographyTTF1 */

typedef struct IEcoTypographyTTF1VTbl {

    /* IEcoUnknown */
    int16_t (*QueryInterface)(/* in */ struct IEcoTypographyTTF1* me, /* in */ const UGUID* riid, /* out */ void **ppv);
    uint32_t (*AddRef)(/* in */ struct IEcoTypographyTTF1* me);
    uint32_t (*Release)(/* in */ struct IEcoTypographyTTF1* me);

    /* IEcoTypographyTTF1 */
    IEcoTypographyTTF1FontFile* (*createFontFile)(/* in */ struct IEcoTypographyTTF1* me);
    IEcoTypographyTTF1TableRecord* (*createTableRecord)(/* in */ struct IEcoTypographyTTF1* me);
    IEcoTypographyTTF1head* (*create_head)(/* in */ struct IEcoTypographyTTF1* me);
    IEcoTypographyTTF1cmap* (*create_cmap)(/* in */ struct IEcoTypographyTTF1* me);
    IEcoTypographyTTF1glyf* (*create_glyf)(/* in */ struct IEcoTypographyTTF1* me);
    IEcoTypographyTTF1maxp* (*create_maxp)(/* in */ struct IEcoTypographyTTF1* me);
    IEcoTypographyTTF1loca* (*create_loca)(/* in */ struct IEcoTypographyTTF1* me);
	 
    IEcoTypographyTTF1FontFile* (*Load)(/* in */ struct IEcoTypographyTTF1* me, /* in */ char_t* fileName);
    int16_t (*Save)(/* in */ struct IEcoTypographyTTF1* me, /* in */ IEcoTypographyTTF1FontFile* pIFontFile, /* in */ char_t* fileName);

} IEcoTypographyTTF1VTbl, *IEcoTypographyTTF1VTblPtr;

interface IEcoTypographyTTF1 {
    struct IEcoTypographyTTF1VTbl *pVTbl;
} IEcoTypographyTTF1;


#endif /* __I_ECO_TYPOGRAPHY_TTF_1_H__ */
