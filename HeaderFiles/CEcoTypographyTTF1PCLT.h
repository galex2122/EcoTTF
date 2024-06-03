/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoTypographyTTF1PCLT
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CEcoTypographyTTF1PCLT
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2016 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECO_TYPOGRAPHY_TTF_1_PCLT_H__
#define __C_ECO_TYPOGRAPHY_TTF_1_PCLT_H__

#include "IdEcoMemoryManager1.h"
#include "IEcoTypographyTTF1PCLT.h"
#include "IdEcoString1.h"
#include "IdEcoList1.h"

typedef struct CEcoTypographyTTF1PCLT {

    /* Таблица функций интерфейса IEcoTypographyTTF1PCLT */
    IEcoTypographyTTF1PCLTVTbl* m_pVTblIPCLT;

    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Интерфейс для работы со строкой */
    IEcoString1* m_pIString;

    /* Данные экземпляра */
    ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR m_Descriptor;
    IEcoList1* m_TableDirectory;

} CEcoTypographyTTF1PCLT, *CEcoTypographyTTF1PCLTPtr;

/* Создание экземпляра */
int16_t createCEcoTypographyTTF1PCLT(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* out */ IEcoTypographyTTF1PCLT** ppIPCLT);
/* Удаление */
void deleteCEcoTypographyTTF1PCLT(/* in */ IEcoTypographyTTF1PCLT* pIPCLT);

#endif /* __C_ECO_TYPOGRAPHY_TTF_1_PCLT_H__ */
