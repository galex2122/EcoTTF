/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoTypographyTTF1OS2
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CEcoTypographyTTF1OS2
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2016 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECO_TYPOGRAPHY_TTF_1_OS2_H__
#define __C_ECO_TYPOGRAPHY_TTF_1_OS2_H__

#include "IdEcoMemoryManager1.h"
#include "IEcoTypographyTTF1OS2.h"
#include "IdEcoString1.h"
#include "IdEcoList1.h"

typedef struct CEcoTypographyTTF1OS2 {

    /* Таблица функций интерфейса IEcoTypographyTTF1OS2 */
    IEcoTypographyTTF1OS2VTbl* m_pVTblIOS2;

    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Интерфейс для работы со строкой */
    IEcoString1* m_pIString;

    /* Данные экземпляра */
    ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR m_Descriptor;
    IEcoList1* m_TableDirectory;

} CEcoTypographyTTF1OS2, *CEcoTypographyTTF1OS2Ptr;

/* Создание экземпляра */
int16_t createCEcoTypographyTTF1OS2(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* out */ IEcoTypographyTTF1OS2** ppIOS2);
/* Удаление */
void deleteCEcoTypographyTTF1OS2(/* in */ IEcoTypographyTTF1OS2* pIOS2);

#endif /* __C_ECO_TYPOGRAPHY_TTF_1_OS2_H__ */
