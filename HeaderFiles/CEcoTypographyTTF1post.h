/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoTypographyTTF1post
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CEcoTypographyTTF1post
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2016 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECO_TYPOGRAPHY_TTF_1_POST_H__
#define __C_ECO_TYPOGRAPHY_TTF_1_POST_H__

#include "IdEcoMemoryManager1.h"
#include "IEcoTypographyTTF1post.h"
#include "IdEcoString1.h"
#include "IdEcoList1.h"

typedef struct CEcoTypographyTTF1post {

    /* Таблица функций интерфейса IEcoTypographyTTF1post */
    IEcoTypographyTTF1postVTbl* m_pVTblIpost;

    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Интерфейс для работы со строкой */
    IEcoString1* m_pIString;

    /* Данные экземпляра */
    ECO_TRUE_TYPE_FONT_1_TABLE_DIRECTORY_DESCRIPTOR m_Descriptor;
    IEcoList1* m_TableDirectory;

} CEcoTypographyTTF1post, *CEcoTypographyTTF1postPtr;

/* Создание экземпляра */
int16_t createCEcoTypographyTTF1post(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* out */ IEcoTypographyTTF1post** ppIpost);
/* Удаление */
void deleteCEcoTypographyTTF1post(/* in */ IEcoTypographyTTF1post* pIpost);

#endif /* __C_ECO_TYPOGRAPHY_TTF_1_POST_H__ */
