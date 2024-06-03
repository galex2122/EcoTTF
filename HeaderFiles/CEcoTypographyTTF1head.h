/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoTypographyTTF1head
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CEcoTypographyTTF1head
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2016 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECO_TYPOGRAPHY_TTF_1_HEAD_H__
#define __C_ECO_TYPOGRAPHY_TTF_1_HEAD_H__

#include "IdEcoMemoryManager1.h"
#include "IEcoTypographyTTF1head.h"

typedef struct CEcoTypographyTTF1head {

    /* Таблица функций интерфейса IEcoTypographyTTF1head */
    IEcoTypographyTTF1headVTbl* m_pVTblIhead;

    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Данные экземпляра */
    ECO_TRUE_TYPE_FONT_1_HEAD_DESCRIPTOR m_Descriptor;

} CEcoTypographyTTF1head, *CEcoTypographyTTF1headPtr;

/* Создание экземпляра */
int16_t createCEcoTypographyTTF1head(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* out */ IEcoTypographyTTF1head** ppIhead);
/* Удаление */
void deleteCEcoTypographyTTF1head(/* in */ IEcoTypographyTTF1head* pIhead);

#endif /* __C_ECO_TYPOGRAPHY_TTF_1_HEAD_H__ */
