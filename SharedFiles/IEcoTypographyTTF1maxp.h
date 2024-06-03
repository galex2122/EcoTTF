/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoTypographyTTF1maxp
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoTypographyTTF1maxp
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

#ifndef __I_ECO_TYPOGRAPHY_TTF_1_MAXP_H__
#define __I_ECO_TYPOGRAPHY_TTF_1_MAXP_H__

#include "IEcoBase1.h"

typedef struct ECO_TRUE_TYPE_FONT_1_MAXP_DESCRIPTOR {
    uint32_t version;                   /* 0x00010000 (1.0) */
    uint16_t numGlyphs;                 /* the number of glyphs in the font */
    uint16_t maxPoints;                 /* points in non-compound glyph */
    uint16_t maxContours;               /* contours in non-compound glyph */
    uint16_t maxComponentPoints;        /* points in compound glyph */
    uint16_t maxComponentContours;      /* contours in compound glyph */
    uint16_t maxZones;                  /* set to 2 */
    uint16_t maxTwilightPoints;         /* points used in Twilight Zone (Z0) */
    uint16_t maxStorage;                /* number of Storage Area locations */
    uint16_t maxFunctionDefs;           /* number of FDEFs */
    uint16_t maxInstructionDefs;        /* number of IDEFs */
    uint16_t maxStackElements;          /* maximum stack depth */
    uint16_t maxSizeOfInstructions;     /* byte count for glyph instructions */
    uint16_t maxComponentElements;      /* number of glyphs referenced at top level */
    uint16_t maxComponentDepth;         /* levels of recursion, set to 0 if font has only simple glyphs */
} ECO_TRUE_TYPE_FONT_1_MAXP_DESCRIPTOR;

/* IEcoTypographyTTF1maxp IID = {4E8A1768-1CDD-42AC-B45B-581DA8B3D988} */
#ifndef __IID_IEcoTypographyTTF1maxp
static const UGUID IID_IEcoTypographyTTF1maxp = { 0x01, 0x10, 0x4E, 0x8A, 0x17, 0x68, 0x1C, 0xDD, 0x42, 0xAC, 0xB4, 0x5B, 0x58, 0x1D, 0xA8, 0xB3, 0xD9, 0x88 };
#endif /* __IID_IEcoTypographyTTF1maxp */

typedef struct IEcoTypographyTTF1maxpVTbl {

    /* IEcoUnknown */
    int16_t (*QueryInterface )(/* in */ struct IEcoTypographyTTF1maxp* me, /* in */ const UGUID* riid, /* out */ void **ppv);
    uint32_t (*AddRef )(/* in */ struct IEcoTypographyTTF1maxp* me);
    uint32_t (*Release )(/* in */ struct IEcoTypographyTTF1maxp* me);

    /* IEcoTypographyTTF1maxp */
    ECO_TRUE_TYPE_FONT_1_MAXP_DESCRIPTOR* (*get_Descriptor)(/* in */ struct IEcoTypographyTTF1maxp* me);
    void (*set_Descriptor)(/* in */ struct IEcoTypographyTTF1maxp* me, /* in */ ECO_TRUE_TYPE_FONT_1_MAXP_DESCRIPTOR* descriptor);

} IEcoTypographyTTF1maxpVTbl, *IEcoTypographyTTF1maxpVTblPtr;

interface IEcoTypographyTTF1maxp {
    struct IEcoTypographyTTF1maxpVTbl *pVTbl;
} IEcoTypographyTTF1maxp;

#endif /* __I_ECO_TYPOGRAPHY_TTF_1_MAXP_H__ */
