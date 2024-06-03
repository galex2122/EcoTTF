/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoTypographyTTF1FontFile
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CEcoTypographyTTF1FontFile
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2016 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECO_TYPOGRAPHY_TTF_1_FONT_FILE_H__
#define __C_ECO_TYPOGRAPHY_TTF_1_FONT_FILE_H__

#include "IdEcoMemoryManager1.h"
#include "IEcoTypographyTTF1FontFile.h"
#include "IdEcoString1.h"
#include "IdEcoList1.h"
#include "IEcoTypographyTTF1Glyf.h"
#include "IEcoTypographyTTF1Cmap.h"

typedef struct CEcoTypographyTTF1FontFile {

    /* Таблица функций интерфейса IEcoTypographyTTF1FontFile */
    IEcoTypographyTTF1FontFileVTbl* m_pVTblIFontFile;

    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Интерфейс для работы со строкой */
    IEcoString1* m_pIString;

    /* Данные экземпляра */
    ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR m_Descriptor;
    IEcoList1* m_TableDirectory;
	IEcoTypographyTTF1glyf* m_GlyfTable;
	IEcoTypographyTTF1cmap* m_CMapTable;

} CEcoTypographyTTF1FontFile, *CEcoTypographyTTF1FontFilePtr;

/* Создание экземпляра */
int16_t createCEcoTypographyTTF1FontFile(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* out */ IEcoTypographyTTF1FontFile** ppIFontFile);
/* Удаление */
void deleteCEcoTypographyTTF1FontFile(/* in */ IEcoTypographyTTF1FontFile* pIFontFile);

#endif /* __C_ECO_TYPOGRAPHY_TTF_1_FONT_FILE_H__ */
