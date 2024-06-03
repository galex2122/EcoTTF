/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoTypographyTTF1hmtx
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CEcoTypographyTTF1hmtx
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2016 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECO_TYPOGRAPHY_TTF_1_HMTX_H__
#define __C_ECO_TYPOGRAPHY_TTF_1_HMTX_H__

#include "IdEcoMemoryManager1.h"
#include "IEcoTypographyTTF1hmtx.h"
#include "IdEcoString1.h"
#include "IdEcoList1.h"

typedef struct CEcoTypographyTTF1hmtx {

    /* Таблица функций интерфейса IEcoTypographyTTF1hmtx */
    IEcoTypographyTTF1hmtxVTbl* m_pVTblIhmtx;

    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Интерфейс для работы со строкой */
    IEcoString1* m_pIString;

    /* Данные экземпляра */
    ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR m_Descriptor;
    IEcoList1* m_TableDirectory;

} CEcoTypographyTTF1hmtx, *CEcoTypographyTTF1hmtxPtr;

/* Создание экземпляра */
int16_t createCEcoTypographyTTF1hmtx(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* out */ IEcoTypographyTTF1hmtx** ppIhmtx);
/* Удаление */
void deleteCEcoTypographyTTF1hmtx(/* in */ IEcoTypographyTTF1hmtx* pIhmtx);

#endif /* __C_ECO_TYPOGRAPHY_TTF_1_HMTX_H__ */
