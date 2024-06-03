/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoTypographyTTF1JSTF
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CEcoTypographyTTF1JSTF
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2016 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECO_TYPOGRAPHY_TTF_1_JSTF_H__
#define __C_ECO_TYPOGRAPHY_TTF_1_JSTF_H__

#include "IdEcoMemoryManager1.h"
#include "IEcoTypographyTTF1JSTF.h"
#include "IdEcoString1.h"
#include "IdEcoList1.h"

typedef struct CEcoTypographyTTF1JSTF {

    /* Таблица функций интерфейса IEcoTypographyTTF1JSTF */
    IEcoTypographyTTF1JSTFVTbl* m_pVTblIJSTF;

    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Интерфейс для работы со строкой */
    IEcoString1* m_pIString;

    /* Данные экземпляра */
    ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR m_Descriptor;
    IEcoList1* m_TableDirectory;

} CEcoTypographyTTF1JSTF, *CEcoTypographyTTF1JSTFPtr;

/* Создание экземпляра */
int16_t createCEcoTypographyTTF1JSTF(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* out */ IEcoTypographyTTF1JSTF** ppIJSTF);
/* Удаление */
void deleteCEcoTypographyTTF1JSTF(/* in */ IEcoTypographyTTF1JSTF* pIJSTF);

#endif /* __C_ECO_TYPOGRAPHY_TTF_1_JSTF_H__ */
