/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoTypographyTTF1DSIG
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CEcoTypographyTTF1DSIG
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2016 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECO_TYPOGRAPHY_TTF_1_DSIG_H__
#define __C_ECO_TYPOGRAPHY_TTF_1_DSIG_H__

#include "IdEcoMemoryManager1.h"
#include "IEcoTypographyTTF1DSIG.h"
#include "IdEcoString1.h"
#include "IdEcoList1.h"

typedef struct CEcoTypographyTTF1DSIG {

    /* Таблица функций интерфейса IEcoTypographyTTF1DSIG */
    IEcoTypographyTTF1DSIGVTbl* m_pVTblIDSIG;

    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Интерфейс для работы со строкой */
    IEcoString1* m_pIString;

    /* Данные экземпляра */
    ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR m_Descriptor;
    IEcoList1* m_TableDirectory;

} CEcoTypographyTTF1DSIG, *CEcoTypographyTTF1DSIGPtr;

/* Создание экземпляра */
int16_t createCEcoTypographyTTF1DSIG(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* out */ IEcoTypographyTTF1DSIG** ppIDSIG);
/* Удаление */
void deleteCEcoTypographyTTF1DSIG(/* in */ IEcoTypographyTTF1DSIG* pIDSIG);

#endif /* __C_ECO_TYPOGRAPHY_TTF_1_DSIG_H__ */
