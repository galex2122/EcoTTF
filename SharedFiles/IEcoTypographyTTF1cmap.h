/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoTypographyTTF1cmap
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoTypographyTTF1cmap
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

#ifndef __I_ECO_TYPOGRAPHY_TTF_1_CMAP_H__
#define __I_ECO_TYPOGRAPHY_TTF_1_CMAP_H__

#include "IEcoBase1.h"

#include "IEcoList1.h"

typedef struct ECO_TRUE_TYPE_FONT_1_CMAP_DESCRIPTOR {
    uint16_t version;               /* Version number (Set to zero) */
    uint16_t numberSubtables;       /* Number of encoding subtables */
} ECO_TRUE_TYPE_FONT_1_CMAP_DESCRIPTOR;

typedef struct ECO_TRUE_TYPE_FONT_1_ENCODING_RECORD_DESCRIPTOR {
    uint16_t platformID;            /* Platform ID. */
    uint16_t encodingID;            /* Platform-specific encoding ID. */
    uint32_t subtableOffset;        /* Byte offset from beginning of table to the subtable for this encoding. */
} ECO_TRUE_TYPE_FONT_1_ENCODING_RECORD_DESCRIPTOR;

/* Format 0: Byte encoding table */
typedef struct ECO_TRUE_TYPE_FONT_1_FORMAT_0_DESCRIPTOR {
    uint16_t format;                /* Format number is set to 0. */
    uint16_t length;                /* This is the length in bytes of the subtable. */
    uint16_t language;              /* For requirements on use of the language field, */
    uint8_t glyphIdArray;           /* An array that maps character codes to glyph index values. */
} ECO_TRUE_TYPE_FONT_1_FORMAT_0_DESCRIPTOR;

/* Format 2: High-byte mapping through table */
typedef struct ECO_TRUE_TYPE_FONT_1_FORMAT_2_DESCRIPTOR {
    uint16_t format;                /* Format number is set to 0. */
    uint16_t length;                /* This is the length in bytes of the subtable. */
    uint16_t language;              /* For requirements on use of the language field, */
    uint8_t subHeaderKeys;          /* Array that maps high bytes to subHeaders. */
} ECO_TRUE_TYPE_FONT_1_FORMAT_2_DESCRIPTOR;


/* Platform IDs */
#define ECO_TTF_1_CMAP_PLATFORM_ID_UNICODE      0
#define ECO_TTF_1_CMAP_PLATFORM_ID_MACINTOSH    1
#define ECO_TTF_1_CMAP_PLATFORM_ID_ISO          2
#define ECO_TTF_1_CMAP_PLATFORM_ID_WINDOWS      3
#define ECO_TTF_1_CMAP_PLATFORM_ID_CUSTOM       4

/* Encoding IDs */
#define ECO_TTF_1_CMAP_ENCODING_ID_UNICODE_1_0              0
#define ECO_TTF_1_CMAP_ENCODING_ID_UNICODE_1_1              1
#define ECO_TTF_1_CMAP_ENCODING_ID_UNICODE_ISO_IEC_10646    2
#define ECO_TTF_1_CMAP_ENCODING_ID_UNICODE_2_0_BMP          3
#define ECO_TTF_1_CMAP_ENCODING_ID_UNICODE_2_0_FULL         4
#define ECO_TTF_1_CMAP_ENCODING_ID_UNICODE_VARIATION        5
#define ECO_TTF_1_CMAP_ENCODING_ID_UNICODE_FULL             6
#define ECO_TTF_1_CMAP_ENCODING_ID_ISO_7_ASCII              0
#define ECO_TTF_1_CMAP_ENCODING_ID_ISO_10646                1
#define ECO_TTF_1_CMAP_ENCODING_ID_ISO_8859_1               2
#define ECO_TTF_1_CMAP_ENCODING_ID_WINDOWS_SYMBOL           0
#define ECO_TTF_1_CMAP_ENCODING_ID_WINDOWS_UNICODE_BMP      1
#define ECO_TTF_1_CMAP_ENCODING_ID_WINDOWS_SHIFT_JIS        2
#define ECO_TTF_1_CMAP_ENCODING_ID_WINDOWS_PRC              3
#define ECO_TTF_1_CMAP_ENCODING_ID_WINDOWS_BIG_5            4
#define ECO_TTF_1_CMAP_ENCODING_ID_WINDOWS_WANSUNG          5
#define ECO_TTF_1_CMAP_ENCODING_ID_WINDOWS_JOHAB            6
#define ECO_TTF_1_CMAP_ENCODING_ID_WINDOWS_UNIVODE_FULL     10


/* IEcoTypographyTTF1cmap IID = {F6E47CBE-C394-446E-A2C6-C781768AB048} */
#ifndef __IID_IEcoTypographyTTF1cmap
static const UGUID IID_IEcoTypographyTTF1cmap = { 0x01, 0x10, 0xF6, 0xE4, 0x7C, 0xBE, 0xC3, 0x94, 0x44, 0x6E, 0xA2, 0xC6, 0xC7, 0x81, 0x76, 0x8A, 0xB0, 0x48 };
#endif /* __IID_IEcoTypographyTTF1cmap */

typedef struct IEcoTypographyTTF1cmapVTbl {

    /* IEcoUnknown */
    int16_t (*QueryInterface )(/* in */ struct IEcoTypographyTTF1cmap* me, /* in */ const UGUID* riid, /* out */ void **ppv);
    uint32_t (*AddRef )(/* in */ struct IEcoTypographyTTF1cmap* me);
    uint32_t (*Release )(/* in */ struct IEcoTypographyTTF1cmap* me);

    /* IEcoTypographyTTF1cmap */
    ECO_TRUE_TYPE_FONT_1_CMAP_DESCRIPTOR* (*get_Descriptor)(/* in */ struct IEcoTypographyTTF1cmap* me);
    void (*set_Descriptor)(/* in */ struct IEcoTypographyTTF1cmap* me, /* in */ ECO_TRUE_TYPE_FONT_1_CMAP_DESCRIPTOR* descriptor);
    IEcoList1* (*get_TableDirectory)(/* in */ struct IEcoTypographyTTF1cmap* me);
    void (*set_TableDirectory)(/* in */ struct IEcoTypographyTTF1cmap* me, /* in */ IEcoList1* pIRecords);

} IEcoTypographyTTF1cmapVTbl, *IEcoTypographyTTF1cmapVTblPtr;

interface IEcoTypographyTTF1cmap {
    struct IEcoTypographyTTF1cmapVTbl *pVTbl;
} IEcoTypographyTTF1cmap;

#endif /* __I_ECO_TYPOGRAPHY_TTF_1_CMAP_H__ */
