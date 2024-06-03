/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoTypographyTTF1name
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CEcoTypographyTTF1name
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2016 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECO_TYPOGRAPHY_TTF_1_NAME_H__
#define __C_ECO_TYPOGRAPHY_TTF_1_NAME_H__

#include "IdEcoMemoryManager1.h"
#include "IEcoTypographyTTF1name.h"
#include "IdEcoString1.h"
#include "IdEcoList1.h"

typedef struct CEcoTypographyTTF1name {

    /* Таблица функций интерфейса IEcoTypographyTTF1name */
    IEcoTypographyTTF1nameVTbl* m_pVTblIname;

    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Интерфейс для работы со строкой */
    IEcoString1* m_pIString;

    /* Данные экземпляра */
    ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR m_Descriptor;
    IEcoList1* m_TableDirectory;

} CEcoTypographyTTF1name, *CEcoTypographyTTF1namePtr;

/* Создание экземпляра */
int16_t createCEcoTypographyTTF1name(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* out */ IEcoTypographyTTF1name** ppIname);
/* Удаление */
void deleteCEcoTypographyTTF1name(/* in */ IEcoTypographyTTF1name* pIname);

#endif /* __C_ECO_TYPOGRAPHY_TTF_1_NAME_H__ */
