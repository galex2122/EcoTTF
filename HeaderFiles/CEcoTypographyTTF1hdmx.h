/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoTypographyTTF1hdmx
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CEcoTypographyTTF1hdmx
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2016 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECO_TYPOGRAPHY_TTF_1_HDMX_H__
#define __C_ECO_TYPOGRAPHY_TTF_1_HDMX_H__

#include "IdEcoMemoryManager1.h"
#include "IEcoTypographyTTF1hdmx.h"
#include "IdEcoString1.h"
#include "IdEcoList1.h"

typedef struct CEcoTypographyTTF1hdmx {

    /* Таблица функций интерфейса IEcoTypographyTTF1hdmx */
    IEcoTypographyTTF1hdmxVTbl* m_pVTblIhdmx;

    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Интерфейс для работы со строкой */
    IEcoString1* m_pIString;

    /* Данные экземпляра */
    ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR m_Descriptor;
    IEcoList1* m_TableDirectory;

} CEcoTypographyTTF1hdmx, *CEcoTypographyTTF1hdmxPtr;

/* Создание экземпляра */
int16_t createCEcoTypographyTTF1hdmx(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* out */ IEcoTypographyTTF1hdmx** ppIhdmx);
/* Удаление */
void deleteCEcoTypographyTTF1hdmx(/* in */ IEcoTypographyTTF1hdmx* pIhdmx);

#endif /* __C_ECO_TYPOGRAPHY_TTF_1_HDMX_H__ */
