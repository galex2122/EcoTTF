/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoTypographyTTF1meta
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CEcoTypographyTTF1meta
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2016 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECO_TYPOGRAPHY_TTF_1_META_H__
#define __C_ECO_TYPOGRAPHY_TTF_1_META_H__

#include "IdEcoMemoryManager1.h"
#include "IEcoTypographyTTF1meta.h"
#include "IdEcoString1.h"
#include "IdEcoList1.h"

typedef struct CEcoTypographyTTF1meta {

    /* Таблица функций интерфейса IEcoTypographyTTF1meta */
    IEcoTypographyTTF1metaVTbl* m_pVTblImeta;

    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Интерфейс для работы со строкой */
    IEcoString1* m_pIString;

    /* Данные экземпляра */
    ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR m_Descriptor;
    IEcoList1* m_TableDirectory;

} CEcoTypographyTTF1meta, *CEcoTypographyTTF1metaPtr;

/* Создание экземпляра */
int16_t createCEcoTypographyTTF1meta(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* out */ IEcoTypographyTTF1meta** ppImeta);
/* Удаление */
void deleteCEcoTypographyTTF1meta(/* in */ IEcoTypographyTTF1meta* pImeta);

#endif /* __C_ECO_TYPOGRAPHY_TTF_1_META_H__ */
