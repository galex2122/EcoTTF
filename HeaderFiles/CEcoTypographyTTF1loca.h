/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoTypographyTTF1loca
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CEcoTypographyTTF1loca
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2016 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECO_TYPOGRAPHY_TTF_1_LOCA_H__
#define __C_ECO_TYPOGRAPHY_TTF_1_LOCA_H__

#include "IdEcoMemoryManager1.h"
#include "IEcoTypographyTTF1loca.h"

typedef struct CEcoTypographyTTF1loca {

    /* Таблица функций интерфейса IEcoTypographyTTF1loca */
    IEcoTypographyTTF1locaVTbl* m_pVTblIloca;

    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Данные экземпляра */
    int16_t m_OffsetFormat;
    byte_t* m_TableData;
    uint32_t m_TableLength;

} CEcoTypographyTTF1loca, *CEcoTypographyTTF1locaPtr;

/* Создание экземпляра */
int16_t createCEcoTypographyTTF1loca(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* out */ IEcoTypographyTTF1loca** ppIloca);
/* Удаление */
void deleteCEcoTypographyTTF1loca(/* in */ IEcoTypographyTTF1loca* pIloca);

#endif /* __C_ECO_TYPOGRAPHY_TTF_1_LOCA_H__ */
