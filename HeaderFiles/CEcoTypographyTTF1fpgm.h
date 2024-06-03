/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoTypographyTTF1fpgm
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CEcoTypographyTTF1fpgm
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2016 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECO_TYPOGRAPHY_TTF_1_FPGM_H__
#define __C_ECO_TYPOGRAPHY_TTF_1_FPGM_H__

#include "IdEcoMemoryManager1.h"
#include "IEcoTypographyTTF1fpgm.h"
#include "IdEcoString1.h"
#include "IdEcoList1.h"

typedef struct CEcoTypographyTTF1fpgm {

    /* Таблица функций интерфейса IEcoTypographyTTF1fpgm */
    IEcoTypographyTTF1fpgmVTbl* m_pVTblIfpgm;

    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Интерфейс для работы со строкой */
    IEcoString1* m_pIString;

    /* Данные экземпляра */
    ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR m_Descriptor;
    IEcoList1* m_TableDirectory;

} CEcoTypographyTTF1fpgm, *CEcoTypographyTTF1fpgmPtr;

/* Создание экземпляра */
int16_t createCEcoTypographyTTF1fpgm(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* out */ IEcoTypographyTTF1fpgm** ppIfpgm);
/* Удаление */
void deleteCEcoTypographyTTF1fpgm(/* in */ IEcoTypographyTTF1fpgm* pIfpgm);

#endif /* __C_ECO_TYPOGRAPHY_TTF_1_FPGM_H__ */
