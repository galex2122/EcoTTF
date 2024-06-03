/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoTypographyTTF1prep
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CEcoTypographyTTF1prep
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2016 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECO_TYPOGRAPHY_TTF_1_PREP_H__
#define __C_ECO_TYPOGRAPHY_TTF_1_PREP_H__

#include "IdEcoMemoryManager1.h"
#include "IEcoTypographyTTF1prep.h"
#include "IdEcoString1.h"
#include "IdEcoList1.h"

typedef struct CEcoTypographyTTF1prep {

    /* Таблица функций интерфейса IEcoTypographyTTF1prep */
    IEcoTypographyTTF1prepVTbl* m_pVTblIprep;

    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Интерфейс для работы со строкой */
    IEcoString1* m_pIString;

    /* Данные экземпляра */
    ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR m_Descriptor;
    IEcoList1* m_TableDirectory;

} CEcoTypographyTTF1prep, *CEcoTypographyTTF1prepPtr;

/* Создание экземпляра */
int16_t createCEcoTypographyTTF1prep(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* out */ IEcoTypographyTTF1prep** ppIprep);
/* Удаление */
void deleteCEcoTypographyTTF1prep(/* in */ IEcoTypographyTTF1prep* pIprep);

#endif /* __C_ECO_TYPOGRAPHY_TTF_1_PREP_H__ */
