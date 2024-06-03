/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoTypographyTTF1glyf
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoTypographyTTF1glyf
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

#ifndef __I_ECO_TYPOGRAPHY_TTF_1_GLYF_H__
#define __I_ECO_TYPOGRAPHY_TTF_1_GLYF_H__

#include "IEcoBase1.h"

#include "IEcoList1.h"

typedef struct ECO_TRUE_TYPE_FONT_1_GLYPH_HEADER_DESCRIPTOR {
    int16_t numberOfContours;  /* If the number of contours is positive or zero, it is a single glyph;
                                   If the number of contours less than zero, the glyph is compound */
    int16_t xMin;              /*Minimum x for coordinate data */
    int16_t yMin;              /*Minimum y for coordinate data */
    int16_t xMax;              /* Maximum x for coordinate data */
    int16_t yMax;              /* Maximum y for coordinate data */
} ECO_TRUE_TYPE_FONT_1_GLYPH_HEADER_DESCRIPTOR;

typedef struct ECO_TRUE_TYPE_FONT_1_GLYPH_SIMPLE_CONTENT {
    IEcoList1* endPtsOfContours;
    uint16_t instructionLength;
    IEcoList1* instructions;
	IEcoList1* flags;
	IEcoList1* xCoordinates;
	IEcoList1* yCoordinates;
} ECO_TRUE_TYPE_FONT_1_GLYPH_SIMPLE_CONTENT;

typedef struct ECO_TRUE_TYPE_FONT_1_GLYPH_POINT{
    int16_t x;
    int16_t y;
	uint8_t isOnCurve;
	int16_t contourNum;
} ECO_TRUE_TYPE_FONT_1_GLYPH_POINT;

typedef struct ECO_TRUE_TYPE_FONT_1_GLYPH_COMPOSITE_CONTENT {
    IEcoList1* components;             
} ECO_TRUE_TYPE_FONT_1_GLYPH_COMPOSITE_CONTENT;

typedef struct ECO_TRUE_TYPE_FONT_1_GLYPH_COMPOSITE_COMPONENT_CONTENT {
    uint16_t flags;  
    uint16_t glyphIndex;            
    int16_t argument1;             
    int16_t argument2;                      
} ECO_TRUE_TYPE_FONT_1_GLYPH_COMPOSITE_COMPONENT_CONTENT;

typedef struct ECO_TRUE_TYPE_FONT_1_GLYPH_COMPONENT_ADDRESS {
    uint8_t isSimple;
    uint32_t indexInArray;
} ECO_TRUE_TYPE_FONT_1_GLYPH_COMPONENT_ADDRESS;

/* IEcoTypographyTTF1glyf IID = {F46473B7-CFA6-4514-9517-DE19AE61DE48} */
#ifndef __IID_IEcoTypographyTTF1glyf
static const UGUID IID_IEcoTypographyTTF1glyf = { 0x01, 0x10, 0xF4, 0x64, 0x73, 0xB7, 0xCF, 0xA6, 0x45, 0x14, 0x95, 0x17, 0xDE, 0x19, 0xAE, 0x61, 0xDE, 0x48 };
#endif /* __IID_IEcoTypographyTTF1glyf */

typedef struct IEcoTypographyTTF1glyfVTbl {

    /* IEcoUnknown */
    int16_t (*QueryInterface )(/* in */ struct IEcoTypographyTTF1glyf* me, /* in */ const UGUID* riid, /* out */ void **ppv);
    uint32_t (*AddRef )(/* in */ struct IEcoTypographyTTF1glyf* me);
    uint32_t (*Release )(/* in */ struct IEcoTypographyTTF1glyf* me);

    /* IEcoTypographyTTF1glyf */
	ECO_TRUE_TYPE_FONT_1_GLYPH_HEADER_DESCRIPTOR* (*get_Descriptor)(/* in */ struct IEcoTypographyTTF1glyf* me, int index);
    void (*set_Descriptor)(/* in */ struct IEcoTypographyTTF1glyf* me, int index,/* in */ ECO_TRUE_TYPE_FONT_1_GLYPH_HEADER_DESCRIPTOR* descriptor);

	ECO_TRUE_TYPE_FONT_1_GLYPH_SIMPLE_CONTENT* (*get_SimpleContent)(/* in */ struct IEcoTypographyTTF1glyf* me, int index);
    uint32_t (*set_SimpleContent)(/* in */ struct IEcoTypographyTTF1glyf* me, int index,/* in */ ECO_TRUE_TYPE_FONT_1_GLYPH_SIMPLE_CONTENT* content);

	ECO_TRUE_TYPE_FONT_1_GLYPH_COMPOSITE_CONTENT* (*get_CompositeContent)(/* in */ struct IEcoTypographyTTF1glyf* me, int index);
    uint32_t (*set_CompositeContent)(/* in */ struct IEcoTypographyTTF1glyf* me, int index,/* in */ ECO_TRUE_TYPE_FONT_1_GLYPH_COMPOSITE_CONTENT* content);

	ECO_TRUE_TYPE_FONT_1_GLYPH_COMPONENT_ADDRESS* (*get_ComponentAddress)(/* in */ struct IEcoTypographyTTF1glyf* me, int index);
    void (*set_ComponentAddress)(/* in */ struct IEcoTypographyTTF1glyf* me, /* in */ ECO_TRUE_TYPE_FONT_1_GLYPH_COMPONENT_ADDRESS* content);

    IEcoList1* (*get_TableDirectory)(/* in */ struct IEcoTypographyTTF1glyf* me);
    void (*set_TableDirectory)(/* in */ struct IEcoTypographyTTF1glyf* me, /* in */ IEcoList1* pIRecords);

	IEcoList1* (*get_GlyfPoints)(/* in */ struct IEcoTypographyTTF1glyf* me, int index);

} IEcoTypographyTTF1glyfVTbl, *IEcoTypographyTTF1glyfVTblPtr;

interface IEcoTypographyTTF1glyf {
    struct IEcoTypographyTTF1glyfVTbl *pVTbl;
} IEcoTypographyTTF1glyf;

#endif /* __I_ECO_TYPOGRAPHY_TTF_1_GLYF_H__ */
