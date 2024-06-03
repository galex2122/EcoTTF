/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoTypographyTTF1kern
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CEcoTypographyTTF1kern
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2016 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECO_TYPOGRAPHY_TTF_1_KERN_H__
#define __C_ECO_TYPOGRAPHY_TTF_1_KERN_H__

#include "IdEcoMemoryManager1.h"
#include "IEcoTypographyTTF1kern.h"
#include "IdEcoString1.h"
#include "IdEcoList1.h"

typedef struct CEcoTypographyTTF1kern {

    /* Таблица функций интерфейса IEcoTypographyTTF1kern */
    IEcoTypographyTTF1kernVTbl* m_pVTblIkern;

    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Интерфейс для работы со строкой */
    IEcoString1* m_pIString;

    /* Данные экземпляра */
    ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR m_Descriptor;
    IEcoList1* m_TableDirectory;

} CEcoTypographyTTF1kern, *CEcoTypographyTTF1kernPtr;

/* Создание экземпляра */
int16_t createCEcoTypographyTTF1kern(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* out */ IEcoTypographyTTF1kern** ppIkern);
/* Удаление */
void deleteCEcoTypographyTTF1kern(/* in */ IEcoTypographyTTF1kern* pIkern);

#endif /* __C_ECO_TYPOGRAPHY_TTF_1_KERN_H__ */
