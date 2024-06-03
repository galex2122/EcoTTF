/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoTypographyTTF1GPOS
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CEcoTypographyTTF1GPOS
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2016 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECO_TYPOGRAPHY_TTF_1_GPOS_H__
#define __C_ECO_TYPOGRAPHY_TTF_1_GPOS_H__

#include "IdEcoMemoryManager1.h"
#include "IEcoTypographyTTF1GPOS.h"
#include "IdEcoString1.h"
#include "IdEcoList1.h"

typedef struct CEcoTypographyTTF1GPOS {

    /* Таблица функций интерфейса IEcoTypographyTTF1GPOS */
    IEcoTypographyTTF1GPOSVTbl* m_pVTblIGPOS;

    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Интерфейс для работы со строкой */
    IEcoString1* m_pIString;

    /* Данные экземпляра */
    ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR m_Descriptor;
    IEcoList1* m_TableDirectory;

} CEcoTypographyTTF1GPOS, *CEcoTypographyTTF1GPOSPtr;

/* Создание экземпляра */
int16_t createCEcoTypographyTTF1GPOS(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* out */ IEcoTypographyTTF1GPOS** ppIGPOS);
/* Удаление */
void deleteCEcoTypographyTTF1GPOS(/* in */ IEcoTypographyTTF1GPOS* pIGPOS);

#endif /* __C_ECO_TYPOGRAPHY_TTF_1_GPOS_H__ */
