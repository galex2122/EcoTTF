/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoTypographyTTF1VDMX
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CEcoTypographyTTF1VDMX
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2016 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECO_TYPOGRAPHY_TTF_1_VDMX_H__
#define __C_ECO_TYPOGRAPHY_TTF_1_VDMX_H__

#include "IdEcoMemoryManager1.h"
#include "IEcoTypographyTTF1VDMX.h"
#include "IdEcoString1.h"
#include "IdEcoList1.h"

typedef struct CEcoTypographyTTF1VDMX {

    /* Таблица функций интерфейса IEcoTypographyTTF1VDMX */
    IEcoTypographyTTF1VDMXVTbl* m_pVTblIVDMX;

    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Интерфейс для работы со строкой */
    IEcoString1* m_pIString;

    /* Данные экземпляра */
    ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR m_Descriptor;
    IEcoList1* m_TableDirectory;

} CEcoTypographyTTF1VDMX, *CEcoTypographyTTF1VDMXPtr;

/* Создание экземпляра */
int16_t createCEcoTypographyTTF1VDMX(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* out */ IEcoTypographyTTF1VDMX** ppIVDMX);
/* Удаление */
void deleteCEcoTypographyTTF1VDMX(/* in */ IEcoTypographyTTF1VDMX* pIVDMX);

#endif /* __C_ECO_TYPOGRAPHY_TTF_1_VDMX_H__ */
