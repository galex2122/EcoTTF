/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoTypographyTTF1cmap
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CEcoTypographyTTF1cmap
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2016 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECO_TYPOGRAPHY_TTF_1_CMAP_H__
#define __C_ECO_TYPOGRAPHY_TTF_1_CMAP_H__

#include "IdEcoMemoryManager1.h"
#include "IEcoTypographyTTF1cmap.h"
#include "IdEcoString1.h"
#include "IdEcoList1.h"

typedef struct CEcoTypographyTTF1cmap {

    /* Таблица функций интерфейса IEcoTypographyTTF1cmap */
    IEcoTypographyTTF1cmapVTbl* m_pVTblIcmap;

    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Интерфейс для работы со строкой */
    IEcoString1* m_pIString;

    /* Данные экземпляра */
    ECO_TRUE_TYPE_FONT_1_CMAP_DESCRIPTOR m_Descriptor;
    IEcoList1* m_TableDirectory;
	IEcoList1* m_EncodingRecords;

} CEcoTypographyTTF1cmap, *CEcoTypographyTTF1cmapPtr;

/* Создание экземпляра */
int16_t createCEcoTypographyTTF1cmap(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* out */ IEcoTypographyTTF1cmap** ppIcmap);
/* Удаление */
void deleteCEcoTypographyTTF1cmap(/* in */ IEcoTypographyTTF1cmap* pIcmap);

#endif /* __C_ECO_TYPOGRAPHY_TTF_1_CMAP_H__ */
