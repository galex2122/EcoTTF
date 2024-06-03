/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoTypographyTTF1hhea
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CEcoTypographyTTF1hhea
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2016 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECO_TYPOGRAPHY_TTF_1_HHEA_H__
#define __C_ECO_TYPOGRAPHY_TTF_1_HHEA_H__

#include "IdEcoMemoryManager1.h"
#include "IEcoTypographyTTF1hhea.h"
#include "IdEcoString1.h"
#include "IdEcoList1.h"

typedef struct CEcoTypographyTTF1hhea {

    /* Таблица функций интерфейса IEcoTypographyTTF1hhea */
    IEcoTypographyTTF1hheaVTbl* m_pVTblIhhea;

    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Интерфейс для работы со строкой */
    IEcoString1* m_pIString;

    /* Данные экземпляра */
    ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR m_Descriptor;
    IEcoList1* m_TableDirectory;

} CEcoTypographyTTF1hhea, *CEcoTypographyTTF1hheaPtr;

/* Создание экземпляра */
int16_t createCEcoTypographyTTF1hhea(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* out */ IEcoTypographyTTF1hhea** ppIhhea);
/* Удаление */
void deleteCEcoTypographyTTF1hhea(/* in */ IEcoTypographyTTF1hhea* pIhhea);

#endif /* __C_ECO_TYPOGRAPHY_TTF_1_HHEA_H__ */
