/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoTypographyTTF1GDEF
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CEcoTypographyTTF1GDEF
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2016 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECO_TYPOGRAPHY_TTF_1_GDEF_H__
#define __C_ECO_TYPOGRAPHY_TTF_1_GDEF_H__

#include "IdEcoMemoryManager1.h"
#include "IEcoTypographyTTF1GDEF.h"
#include "IdEcoString1.h"
#include "IdEcoList1.h"

typedef struct CEcoTypographyTTF1GDEF {

    /* Таблица функций интерфейса IEcoTypographyTTF1GDEF */
    IEcoTypographyTTF1GDEFVTbl* m_pVTblIGDEF;

    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Интерфейс для работы со строкой */
    IEcoString1* m_pIString;

    /* Данные экземпляра */
    ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR m_Descriptor;
    IEcoList1* m_TableDirectory;

} CEcoTypographyTTF1GDEF, *CEcoTypographyTTF1GDEFPtr;

/* Создание экземпляра */
int16_t createCEcoTypographyTTF1GDEF(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* out */ IEcoTypographyTTF1GDEF** ppIGDEF);
/* Удаление */
void deleteCEcoTypographyTTF1GDEF(/* in */ IEcoTypographyTTF1GDEF* pIGDEF);

#endif /* __C_ECO_TYPOGRAPHY_TTF_1_GDEF_H__ */
