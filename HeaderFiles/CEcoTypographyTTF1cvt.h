/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoTypographyTTF1cvt
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CEcoTypographyTTF1cvt
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2016 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECO_TYPOGRAPHY_TTF_1_CVT_H__
#define __C_ECO_TYPOGRAPHY_TTF_1_CVT_H__

#include "IdEcoMemoryManager1.h"
#include "IEcoTypographyTTF1cvt.h"
#include "IdEcoString1.h"
#include "IdEcoList1.h"

typedef struct CEcoTypographyTTF1cvt {

    /* Таблица функций интерфейса IEcoTypographyTTF1cvt */
    IEcoTypographyTTF1cvtVTbl* m_pVTblIcvt;

    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Интерфейс для работы со строкой */
    IEcoString1* m_pIString;

    /* Данные экземпляра */
    ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR m_Descriptor;
    IEcoList1* m_TableDirectory;

} CEcoTypographyTTF1cvt, *CEcoTypographyTTF1cvtPtr;

/* Создание экземпляра */
int16_t createCEcoTypographyTTF1cvt(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* out */ IEcoTypographyTTF1cvt** ppIcvt);
/* Удаление */
void deleteCEcoTypographyTTF1cvt(/* in */ IEcoTypographyTTF1cvt* pIcvt);

#endif /* __C_ECO_TYPOGRAPHY_TTF_1_CVT_H__ */
