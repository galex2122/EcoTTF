/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoTypographyTTF1gasp
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CEcoTypographyTTF1gasp
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2016 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECO_TYPOGRAPHY_TTF_1_GASP_H__
#define __C_ECO_TYPOGRAPHY_TTF_1_GASP_H__

#include "IdEcoMemoryManager1.h"
#include "IEcoTypographyTTF1gasp.h"
#include "IdEcoString1.h"
#include "IdEcoList1.h"

typedef struct CEcoTypographyTTF1gasp {

    /* Таблица функций интерфейса IEcoTypographyTTF1gasp */
    IEcoTypographyTTF1gaspVTbl* m_pVTblIgasp;

    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Интерфейс для работы со строкой */
    IEcoString1* m_pIString;

    /* Данные экземпляра */
    ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR m_Descriptor;
    IEcoList1* m_TableDirectory;

} CEcoTypographyTTF1gasp, *CEcoTypographyTTF1gaspPtr;

/* Создание экземпляра */
int16_t createCEcoTypographyTTF1gasp(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* out */ IEcoTypographyTTF1gasp** ppIgasp);
/* Удаление */
void deleteCEcoTypographyTTF1gasp(/* in */ IEcoTypographyTTF1gasp* pIgasp);

#endif /* __C_ECO_TYPOGRAPHY_TTF_1_GASP_H__ */
