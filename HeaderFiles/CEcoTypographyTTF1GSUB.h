/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoTypographyTTF1GSUB
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CEcoTypographyTTF1GSUB
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2016 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECO_TYPOGRAPHY_TTF_1_GSUB_H__
#define __C_ECO_TYPOGRAPHY_TTF_1_GSUB_H__

#include "IdEcoMemoryManager1.h"
#include "IEcoTypographyTTF1GSUB.h"
#include "IdEcoString1.h"
#include "IdEcoList1.h"

typedef struct CEcoTypographyTTF1GSUB {

    /* Таблица функций интерфейса IEcoTypographyTTF1GSUB */
    IEcoTypographyTTF1GSUBVTbl* m_pVTblIGSUB;

    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Интерфейс для работы со строкой */
    IEcoString1* m_pIString;

    /* Данные экземпляра */
    ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR m_Descriptor;
    IEcoList1* m_TableDirectory;

} CEcoTypographyTTF1GSUB, *CEcoTypographyTTF1GSUBPtr;

/* Создание экземпляра */
int16_t createCEcoTypographyTTF1GSUB(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* out */ IEcoTypographyTTF1GSUB** ppIGSUB);
/* Удаление */
void deleteCEcoTypographyTTF1GSUB(/* in */ IEcoTypographyTTF1GSUB* pIGSUB);

#endif /* __C_ECO_TYPOGRAPHY_TTF_1_GSUB_H__ */
