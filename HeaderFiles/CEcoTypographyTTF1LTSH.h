/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoTypographyTTF1LTSH
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CEcoTypographyTTF1LTSH
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2016 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECO_TYPOGRAPHY_TTF_1_LTSH_H__
#define __C_ECO_TYPOGRAPHY_TTF_1_LTSH_H__

#include "IdEcoMemoryManager1.h"
#include "IEcoTypographyTTF1LTSH.h"
#include "IdEcoString1.h"
#include "IdEcoList1.h"

typedef struct CEcoTypographyTTF1LTSH {

    /* Таблица функций интерфейса IEcoTypographyTTF1LTSH */
    IEcoTypographyTTF1LTSHVTbl* m_pVTblILTSH;

    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Интерфейс для работы со строкой */
    IEcoString1* m_pIString;

    /* Данные экземпляра */
    ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR m_Descriptor;
    IEcoList1* m_TableDirectory;

} CEcoTypographyTTF1LTSH, *CEcoTypographyTTF1LTSHPtr;

/* Создание экземпляра */
int16_t createCEcoTypographyTTF1LTSH(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* out */ IEcoTypographyTTF1LTSH** ppILTSH);
/* Удаление */
void deleteCEcoTypographyTTF1LTSH(/* in */ IEcoTypographyTTF1LTSH* pILTSH);

#endif /* __C_ECO_TYPOGRAPHY_TTF_1_LTSH_H__ */
