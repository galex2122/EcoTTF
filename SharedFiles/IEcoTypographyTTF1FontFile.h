/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoTypographyTTF1FontFile
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoTypographyTTF1FontFile
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

#ifndef __I_ECO_TYPOGRAPHY_TTF_1_FONT_FILE_H__
#define __I_ECO_TYPOGRAPHY_TTF_1_FONT_FILE_H__

#include "IEcoBase1.h"
#include "IEcoList1.h"
#include "IEcoTypographyTTF1glyf.h"
#include "IEcoTypographyTTF1Cmap.h"

typedef struct ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR {
    uint32_t sfntVersion;
    uint16_t numTables;
    uint16_t searchRange;
    uint16_t entrySelector;
    uint16_t rangeShift;
} ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR;


/* IEcoTypographyTTF1FontFile IID = {04052579-D1E5-4967-BF59-E23181B206D6} */
#ifndef __IID_IEcoTypographyTTF1FontFile
static const UGUID IID_IEcoTypographyTTF1FontFile = { 0x01, 0x10, 0x04, 0x05, 0x25, 0x79, 0xD1, 0xE5, 0x49, 0x67, 0xBF, 0x59, 0xE2, 0x31, 0x81, 0xB2, 0x06, 0xD6 };
#endif /* __IID_IEcoTypographyTTF1FontFile */

typedef struct IEcoTypographyTTF1FontFileVTbl {

    /* IEcoUnknown */
    int16_t (*QueryInterface )(/* in */ struct IEcoTypographyTTF1FontFile* me, /* in */ const UGUID* riid, /* out */ void **ppv);
    uint32_t (*AddRef )(/* in */ struct IEcoTypographyTTF1FontFile* me);
    uint32_t (*Release )(/* in */ struct IEcoTypographyTTF1FontFile* me);

    /* IEcoTypographyTTF1FontFile */
    ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR* (*get_Descriptor)(/* in */ struct IEcoTypographyTTF1FontFile* me);
    void (*set_Descriptor)(/* in */ struct IEcoTypographyTTF1FontFile* me, /* in */ ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR* descriptor);
	IEcoTypographyTTF1glyf* (*get_GlyfTable)(/* in */ struct IEcoTypographyTTF1FontFile* me);
	void (*set_GlyfTable)(/* in */ struct IEcoTypographyTTF1FontFile* me, /* in */ IEcoTypographyTTF1glyf* glyfTable);
	IEcoTypographyTTF1cmap* (*get_CMapTable)(/* in */ struct IEcoTypographyTTF1FontFile* me);
	void (*set_CMapTable)(/* in */ struct IEcoTypographyTTF1FontFile* me, /* in */ IEcoTypographyTTF1cmap* cMapTable);
    IEcoList1* (*get_TableDirectory)(/* in */ struct IEcoTypographyTTF1FontFile* me);
    void (*set_TableDirectory)(/* in */ struct IEcoTypographyTTF1FontFile* me, /* in */ IEcoList1* pIRecords);

} IEcoTypographyTTF1FontFileVTbl, *IEcoTypographyTTF1FontFileVTblPtr;

interface IEcoTypographyTTF1FontFile {
    struct IEcoTypographyTTF1FontFileVTbl *pVTbl;
} IEcoTypographyTTF1FontFile;

#endif /* __I_ECO_TYPOGRAPHY_TTF_1_FONT_FILE_H__ */
